/* /////////////////////////////////////////////////////////////////////////
 * File:    test/performance/b64/main.cpp
 *
 * Purpose: Times encoding and decoding via the C API and the C++ API,
 *          across a range of block sizes and line-length settings. Each
 *          group is one scenario (encode / decode) and one block size;
 *          SIS_PERFTESTS_GROUPGAPS=1 (or --gap-groups on the runner)
 *          separates the groups. The B64_PERF_BYTES environment variable
 *          sets the volume of data processed per row.
 *
 * Created: 28th October 2026
 * Updated: 28th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if !defined(__cplusplus) || \
    __cplusplus < 201103L
# error Requires C++11 or later
#endif


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <b64/b64.hpp>

#include <stlsoft/conversion/number/grouping_functions.hpp>
#include <stlsoft/diagnostics/std_chrono_hrc_stopwatch.hpp>
#include <stlsoft/stlsoft.h>

#include "perf_group_gaps.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

typedef stlsoft::std_chrono_hrc_stopwatch                   stopwatch_t;
typedef stopwatch_t::interval_type                          interval_t;


/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

namespace {

size_t const SIZES[] =
{
    1u,
    16u,
    64u,
    256u,
    4096u,
    65536u,
};

int const   LINE_LEN_FLAGS_64   =   b64::B64_F_LINE_LEN_64;
int const   LINE_LEN_FLAGS_76   =   b64::B64_F_LINE_LEN_76;
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

namespace {

typedef b64::b64_char_t                                     char_t;

struct context
{
    unsigned char const*    bytes;
    size_t                  n;
    char_t const*           enc;        // unwrapped
    size_t                  enc_len;
    char_t const*           enc_76;     // wrapped at 76
    size_t                  enc_76_len;
    char_t*                 enc_buf;
    size_t                  enc_buf_len;
    unsigned char*          dec_buf;
    size_t                  dec_buf_len;
};

typedef uint64_t (scenario_fn_t)(context const&);

struct impl
{
    char const*     name;
    scenario_fn_t*  fn;
};
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

namespace {

template <ss_typename_param_k T_integer>
std::string
thousands(
    T_integer const& v
)
{
    char    dest[41];

    (void)stlsoft::format_thousands(dest, STLSOFT_NUM_ELEMENTS(dest), "3;0", v);

    return std::string(dest);
}

size_t
env_size_t(
    char const* name
,   size_t      default_value
)
{
#if defined(_MSC_VER)
# pragma warning(push)
# pragma warning(disable : 4996)
#endif
    char const* const env = ::getenv(name);
#if defined(_MSC_VER)
# pragma warning(pop)
#endif

    if (NULL == env ||
        '\0' == env[0])
    {
        return default_value;
    }

    char*               end =   NULL;
    unsigned long const v   =   ::strtoul(env, &end, 10);

    if (end == env ||
        '\0' != *end ||
        0 == v)
    {
        return default_value;
    }

    return static_cast<size_t>(v);
}

size_t
bytes_per_row()
{
#ifdef NDEBUG

    return env_size_t("B64_PERF_BYTES", 64u * 1024u * 1024u);
#else

    return env_size_t("B64_PERF_BYTES", 1u * 1024u * 1024u);
#endif
}


/* encode */

uint64_t
encode_c(
    context const& c
)
{
    size_t const r = b64::b64_encode(c.bytes, c.n, c.enc_buf, c.enc_buf_len);

    return r + static_cast<unsigned char>(c.enc_buf[0]);
}

uint64_t
encode_c_line_len_64(
    context const& c
)
{
    size_t const r = b64::b64_encode2(c.bytes, c.n, c.enc_buf, c.enc_buf_len, b64::B64_F_LINE_LEN_64, 0, NULL);

    return r + static_cast<unsigned char>(c.enc_buf[0]);
}

uint64_t
encode_c_line_len_76(
    context const& c
)
{
    size_t const r = b64::b64_encode2(c.bytes, c.n, c.enc_buf, c.enc_buf_len, b64::B64_F_LINE_LEN_76, 0, NULL);

    return r + static_cast<unsigned char>(c.enc_buf[0]);
}

uint64_t
encode_cxx(
    context const& c
)
{
    b64::string_t const s = b64::encode(c.bytes, c.n);

    return s.size() + static_cast<unsigned char>(s[0]);
}

uint64_t
encode_cxx_line_len_64(
    context const& c
)
{
    b64::string_t const s = b64::encode(c.bytes, c.n, LINE_LEN_FLAGS_64);

    return s.size() + static_cast<unsigned char>(s[0]);
}

uint64_t
encode_cxx_line_len_76(
    context const& c
)
{
    b64::string_t const s = b64::encode(c.bytes, c.n, LINE_LEN_FLAGS_76);

    return s.size() + static_cast<unsigned char>(s[0]);
}


/* decode */

uint64_t
decode_c(
    context const& c
)
{
    size_t const r = b64::b64_decode(c.enc, c.enc_len, c.dec_buf, c.dec_buf_len);

    return r + c.dec_buf[0];
}

uint64_t
decode_c_line_len_76(
    context const& c
)
{
    size_t const r = b64::b64_decode(c.enc_76, c.enc_76_len, c.dec_buf, c.dec_buf_len);

    return r + c.dec_buf[0];
}

uint64_t
decode_cxx(
    context const& c
)
{
    b64::blob_t const b = b64::decode(c.enc, c.enc_len);

    return b.size() + b[0];
}

uint64_t
decode_cxx_line_len_76(
    context const& c
)
{
    b64::blob_t const b = b64::decode(c.enc_76, c.enc_76_len);

    return b.size() + b[0];
}


/* timing */

interval_t
time_iterations(
    context const&  c
,   scenario_fn_t*  fn
,   size_t          num_iterations
,   uint64_t&       anchor
)
{
    stopwatch_t sw;

    anchor = 0;

    sw.start();

    for (size_t i = 0; num_iterations != i; ++i)
    {
        anchor += fn(c);
    }

    sw.stop();

    return sw.get_nanoseconds();
}

void
display_results_title()
{
    std::cout
        << '\t'
        << std::setw(10) << std::left << "scenario"
        << '\t'
        << std::setw(8) << std::right << "size"
        << '\t'
        << std::setw(24) << std::left << "impl"
        << '\t'
        << std::setw(12) << std::right << "#iters"
        << '\t'
        << std::setw(16) << std::right << "tm (ns)"
        << '\t'
        << std::setw(12) << std::right << "ns/op"
        << '\t'
        << std::setw(12) << std::right << "MiB/s"
        << '\t'
        << "anchor"
        << std::endl;
}

void
display_results(
    char const*     scenario
,   size_t          size
,   char const*     impl_name
,   size_t          num_iterations
,   interval_t      tm_ns
,   uint64_t        anchor
)
{
    double const ns_op  =   static_cast<double>(tm_ns) / static_cast<double>(num_iterations);
    double const mib_s  =   (0 == tm_ns)
                                ? 0.0
                                : (static_cast<double>(size) * static_cast<double>(num_iterations) / 1048576.0) / (static_cast<double>(tm_ns) / 1000000000.0)
                                ;

    std::cout
        << '\t'
        << std::setw(10) << std::left << scenario
        << '\t'
        << std::setw(8) << std::right << thousands(size)
        << '\t'
        << std::setw(24) << std::left << impl_name
        << '\t'
        << std::setw(12) << std::right << thousands(num_iterations)
        << '\t'
        << std::setw(16) << std::right << thousands(tm_ns)
        << '\t'
        << std::setw(12) << std::right << std::fixed << std::setprecision(1) << ns_op
        << '\t'
        << std::setw(12) << std::right << std::fixed << std::setprecision(1) << mib_s
        << '\t'
        << anchor
        << std::endl;
}

void
run_group(
    char const*     scenario
,   impl const*     impls
,   size_t          num_impls
,   context const&  c
)
{
    /* Gap between (scenario, size) groups. */
    std::string const group_key = std::string(scenario) + ":" + std::to_string(c.n);

    perf_maybe_emit_group_gap(std::cout, group_key.c_str());

    size_t const num_iterations = (std::max)(static_cast<size_t>(10), bytes_per_row() / c.n);

    for (size_t i = 0; num_impls != i; ++i)
    {
        impl const& im = impls[i];

        for (int W = 2; 0 != W; --W)
        {
            uint64_t            anchor  =   0;
            interval_t const    tm_ns   =   time_iterations(c, im.fn, num_iterations, anchor);

            if (1 == W)
            {
                display_results(scenario, c.n, im.name, num_iterations, tm_ns, anchor);
            }
        }
    }
}
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /*argc*/, char* /*argv*/[])
{
    impl const ENCODE_IMPLS[] =
    {
        { "C b64_encode", encode_c, },
        { "C b64_encode2 /64", encode_c_line_len_64, },
        { "C b64_encode2 /76", encode_c_line_len_76, },
        { "C++ encode", encode_cxx, },
        { "C++ encode /64", encode_cxx_line_len_64, },
        { "C++ encode /76", encode_cxx_line_len_76, },
    };

    impl const DECODE_IMPLS[] =
    {
        { "C b64_decode", decode_c, },
        { "C b64_decode /76", decode_c_line_len_76, },
        { "C++ decode", decode_cxx, },
        { "C++ decode /76", decode_cxx_line_len_76, },
    };

    std::cout
        << "test.performance.b64: encode/decode timings via C and C++ APIs"
        << " (human attention; not a CI gate). Prefer Release builds."
        << std::endl
        << "Env: B64_PERF_BYTES"
        << std::endl
        ;
    perf_maybe_emit_groupgaps_banner(std::cout);

    display_results_title();

    // build the per-size fixtures
    struct fixture
    {
        std::vector<unsigned char>  bytes;
        std::string                 enc;
        std::string                 enc_76;
        std::vector<char_t>         enc_buf;
        std::vector<unsigned char>  dec_buf;
    };

    std::vector<fixture> fixtures(STLSOFT_NUM_ELEMENTS(SIZES));

    for (size_t i = 0; STLSOFT_NUM_ELEMENTS(SIZES) != i; ++i)
    {
        fixture&        f   =   fixtures[i];
        size_t const    n   =   SIZES[i];

        f.bytes.resize(n);

        for (size_t j = 0; n != j; ++j)
        {
            f.bytes[j] = static_cast<unsigned char>((j * 131u + 7u) & 0xffu);
        }

        f.enc       =   b64::encode(&f.bytes[0], n);
        f.enc_76    =   b64::encode(&f.bytes[0], n, b64::B64_F_LINE_LEN_76);

        size_t const enc_cap = b64::b64_encode2(&f.bytes[0], n, NULL, 0, b64::B64_F_LINE_LEN_64, 0, NULL);

        f.enc_buf.resize(enc_cap + 1);
        f.dec_buf.resize(n + 4);
    }

    char const* const SCENARIOS[] =
    {
        "encode",
        "decode",
    };

    for (size_t s = 0; STLSOFT_NUM_ELEMENTS(SCENARIOS) != s; ++s)
    {
        for (size_t i = 0; STLSOFT_NUM_ELEMENTS(SIZES) != i; ++i)
        {
            fixture&    f = fixtures[i];
            context     c;

            c.bytes         =   &f.bytes[0];
            c.n             =   SIZES[i];
            c.enc           =   f.enc.data();
            c.enc_len       =   f.enc.size();
            c.enc_76        =   f.enc_76.data();
            c.enc_76_len    =   f.enc_76.size();
            c.enc_buf       =   &f.enc_buf[0];
            c.enc_buf_len   =   f.enc_buf.size();
            c.dec_buf       =   &f.dec_buf[0];
            c.dec_buf_len   =   f.dec_buf.size();

            if (0 == s)
            {
                run_group(SCENARIOS[s], ENCODE_IMPLS, STLSOFT_NUM_ELEMENTS(ENCODE_IMPLS), c);
            }
            else
            {
                run_group(SCENARIOS[s], DECODE_IMPLS, STLSOFT_NUM_ELEMENTS(DECODE_IMPLS), c);
            }
        }
    }

    return EXIT_SUCCESS;
}

/* ///////////////////////////// end of file //////////////////////////// */

