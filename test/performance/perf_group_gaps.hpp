/* /////////////////////////////////////////////////////////////////////////
 * File:    test/performance/perf_group_gaps.hpp
 *
 * Purpose: Shared helpers for optional separators between logical groups
 *          in performance-test output (SIS_PERFTESTS_GROUPGAPS). TTY emits
 *          a blank line; non-TTY / CI emits a visible `\t----------` rule.
 *
 * Created: 28th October 2026
 * Updated: 28th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef B64_INCL_TEST_PERFORMANCE_HPP_PERF_GROUP_GAPS
#define B64_INCL_TEST_PERFORMANCE_HPP_PERF_GROUP_GAPS


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <platformstl/system/console_functions.h>

#include <cstdio>
#include <iostream>
#include <ostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Returns true when the named environment variable is a recognised truey
 * form (`1` / `ok` / `on` / `true` / `yes` / `y`, and uppercase forms).
 */
inline
bool
perf_env_is_truey(
    char const* name
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

    if (NULL == env || '\0' == *env)
    {
        return false;
    }

    if (0 == ::strcmp(env, "1") ||
        0 == ::strcmp(env, "ok") ||
        0 == ::strcmp(env, "on") ||
        0 == ::strcmp(env, "true") ||
        0 == ::strcmp(env, "yes") ||
        0 == ::strcmp(env, "y") ||
        0 == ::strcmp(env, "OK") ||
        0 == ::strcmp(env, "ON") ||
        0 == ::strcmp(env, "TRUE") ||
        0 == ::strcmp(env, "YES") ||
        0 == ::strcmp(env, "Y"))
    {
        return true;
    }

    return false;
}

/** Emit a group separator on `stm`: blank line on a TTY; `\t----------`
 * otherwise (GitHub Actions strips bare blank lines from log UI).
 */
inline
void
perf_emit_group_separator(
    std::ostream& stm
)
{
    // Bare blank lines are stripped by GitHub Actions log UI; use a
    // visible rule when stdout is not a TTY (CI / redirected logs).
    if (platformstl::isatty(stdout))
    {
        stm << std::endl;
    }
    else
    {
        stm << "\t----------" << std::endl;
    }
}

/** FILE* overload of the group separator. */
inline
void
perf_emit_group_separator(
    FILE* fp
)
{
    if (platformstl::isatty(fp))
    {
        std::fputc('\n', fp);
    }
    else
    {
        std::fputs("\t----------\n", fp);
    }
}

/** When `SIS_PERFTESTS_GROUPGAPS` is truey, emit a group separator on
 * `stm` when `group_key` differs from the previous call (not before the
 * first).
 */
inline
void
perf_maybe_emit_group_gap(
    std::ostream&   stm
,   char const*     group_key
)
{
    static bool have_prev = false;
    static char prev_key[128] = "";

    if (!perf_env_is_truey("SIS_PERFTESTS_GROUPGAPS"))
    {
        return;
    }

    if (NULL == group_key)
    {
        group_key = "";
    }

    if (have_prev && 0 != ::strcmp(prev_key, group_key))
    {
        perf_emit_group_separator(stm);
    }

    ::snprintf(prev_key, sizeof(prev_key), "%s", group_key);
    have_prev = true;
}

/** FILE* overload for harnesses that print via `fprintf(stdout, ...)`. */
inline
void
perf_maybe_emit_group_gap(
    FILE*           fp
,   char const*     group_key
)
{
    static bool have_prev = false;
    static char prev_key[128] = "";

    if (!perf_env_is_truey("SIS_PERFTESTS_GROUPGAPS"))
    {
        return;
    }

    if (NULL == group_key)
    {
        group_key = "";
    }

    if (have_prev && 0 != ::strcmp(prev_key, group_key))
    {
        perf_emit_group_separator(fp);
    }

    ::snprintf(prev_key, sizeof(prev_key), "%s", group_key);
    have_prev = true;
}

/** When `SIS_PERFTESTS_GROUPGAPS` is truey, print the one-line Env banner. */
inline
void
perf_maybe_emit_groupgaps_banner(
    std::ostream& stm
)
{
    if (perf_env_is_truey("SIS_PERFTESTS_GROUPGAPS"))
    {
        stm
            << "Env: SIS_PERFTESTS_GROUPGAPS=1"
            << std::endl;
    }
}

/** FILE* overload of the Env banner. */
inline
void
perf_maybe_emit_groupgaps_banner(
    FILE* fp
)
{
    if (perf_env_is_truey("SIS_PERFTESTS_GROUPGAPS"))
    {
        std::fputs("Env: SIS_PERFTESTS_GROUPGAPS=1\n", fp);
    }
}


/* ////////////////////////////////////////////////////////////////////// */

#endif /* !B64_INCL_TEST_PERFORMANCE_HPP_PERF_GROUP_GAPS */

/* ///////////////////////////// end of file //////////////////////////// */
