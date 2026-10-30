/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/b64.cxx/entry.cpp
 *
 * Purpose: Unit test for C++ API.
 *
 * Created: 21st April 2009
 * Updated: 30th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <b64/b64.hpp>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/string/simple_string.hpp>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

static void TEST_encode_NULL();
static void TEST_encode_EMPTY();
static void TEST_encode_1_BYTE_0();
static void TEST_encode_1_BYTE_1();
static void TEST_encode_5_BYTES_ALL_1S();
static void TEST_encode_5_BYTES_1_THEN_2S();
static void TEST_encode_8_BYTES_ALL_1S();
static void TEST_encode_8_BYTES_ASCENDING();
static void TEST_encode_8_BYTES_LINE_LEN_40();
static void TEST_encode_8_BYTES_LINE_LEN_4();
static void TEST_encode_80_BYTES_NEGATIVE_LINE_LEN_IS_64();
static void TEST_encode_80_BYTES_LINE_LEN_64();
static void TEST_encode_80_BYTES_LINE_LEN_76();
static void TEST_encode_80_BYTES_LINE_LEN_80();

static void TEST_encode_1_BYTE_10(void);
static void TEST_encode_1_BYTE_100(void);
static void TEST_encode_1_BYTE_128(void);
static void TEST_encode_1_BYTE_255(void);
static void TEST_encode_TEXT_STRING(void);
static void TEST_encode_15_BYTES_WITH_NEGATIVE_VALUES(void);

static void TEST_decode_PTR_AND_LEN_UNKNOWN_CHAR_THROWS(void);
static void TEST_decode_NUL_TERMINATED_UNKNOWN_CHAR_THROWS(void);
static void TEST_decode_NUL_TERMINATED_STOP_ON_NOTHING_DOES_NOT_THROW(void);
static void TEST_decode_SIMPLE_STRING_UNKNOWN_CHAR_THROWS(void);
static void TEST_decode_SIMPLE_STRING_STOP_ON_NOTHING_DOES_NOT_THROW(void);
static void TEST_decode_STRING_T_UNKNOWN_CHAR_THROWS(void);
static void TEST_decode_STRING_T_AND_FLAGS_STOP_ON_NOTHING_DOES_NOT_THROW(void);
static void TEST_decode_FLAGS_AND_STRING_T_STOP_ON_NOTHING_DOES_NOT_THROW(void);
static void TEST_decode_STRING_T_STOP_ON_BAD_CHAR_REPORTS_BADCHAR_AND_RC(void);
static void TEST_decode_PTR_AND_LEN_STOP_ON_BAD_CHAR_REPORTS_BADCHAR_AND_RC(void);
static void TEST_decode_PTR_AND_LEN_STOP_ON_BAD_CHAR_THROWS_WITH_BADCHAR(void);
} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER(__FILE__, verbosity))
    {
        XTESTS_RUN_CASE(TEST_encode_NULL);
        XTESTS_RUN_CASE(TEST_encode_EMPTY);
        XTESTS_RUN_CASE(TEST_encode_1_BYTE_0);
        XTESTS_RUN_CASE(TEST_encode_1_BYTE_1);
        XTESTS_RUN_CASE(TEST_encode_5_BYTES_ALL_1S);
        XTESTS_RUN_CASE(TEST_encode_5_BYTES_1_THEN_2S);
        XTESTS_RUN_CASE(TEST_encode_8_BYTES_ALL_1S);
        XTESTS_RUN_CASE(TEST_encode_8_BYTES_ASCENDING);
        XTESTS_RUN_CASE(TEST_encode_8_BYTES_LINE_LEN_40);
        XTESTS_RUN_CASE(TEST_encode_8_BYTES_LINE_LEN_4);
        XTESTS_RUN_CASE(TEST_encode_80_BYTES_NEGATIVE_LINE_LEN_IS_64);
        XTESTS_RUN_CASE(TEST_encode_80_BYTES_LINE_LEN_64);
        XTESTS_RUN_CASE(TEST_encode_80_BYTES_LINE_LEN_76);
        XTESTS_RUN_CASE(TEST_encode_80_BYTES_LINE_LEN_80);


        XTESTS_RUN_CASE(TEST_encode_1_BYTE_10);
        XTESTS_RUN_CASE(TEST_encode_1_BYTE_100);
        XTESTS_RUN_CASE(TEST_encode_1_BYTE_128);
        XTESTS_RUN_CASE(TEST_encode_1_BYTE_255);
        XTESTS_RUN_CASE(TEST_encode_TEXT_STRING);
        XTESTS_RUN_CASE(TEST_encode_15_BYTES_WITH_NEGATIVE_VALUES);

        XTESTS_RUN_CASE(TEST_decode_PTR_AND_LEN_UNKNOWN_CHAR_THROWS);
        XTESTS_RUN_CASE(TEST_decode_NUL_TERMINATED_UNKNOWN_CHAR_THROWS);
        XTESTS_RUN_CASE(TEST_decode_NUL_TERMINATED_STOP_ON_NOTHING_DOES_NOT_THROW);
        XTESTS_RUN_CASE(TEST_decode_SIMPLE_STRING_UNKNOWN_CHAR_THROWS);
        XTESTS_RUN_CASE(TEST_decode_SIMPLE_STRING_STOP_ON_NOTHING_DOES_NOT_THROW);
        XTESTS_RUN_CASE(TEST_decode_STRING_T_UNKNOWN_CHAR_THROWS);
        XTESTS_RUN_CASE(TEST_decode_STRING_T_AND_FLAGS_STOP_ON_NOTHING_DOES_NOT_THROW);
        XTESTS_RUN_CASE(TEST_decode_FLAGS_AND_STRING_T_STOP_ON_NOTHING_DOES_NOT_THROW);
        XTESTS_RUN_CASE(TEST_decode_STRING_T_STOP_ON_BAD_CHAR_REPORTS_BADCHAR_AND_RC);
        XTESTS_RUN_CASE(TEST_decode_PTR_AND_LEN_STOP_ON_BAD_CHAR_REPORTS_BADCHAR_AND_RC);
        XTESTS_RUN_CASE(TEST_decode_PTR_AND_LEN_STOP_ON_BAD_CHAR_THROWS_WITH_BADCHAR);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{

//  inline string_t encode(void const *src, size_t srcSize);
//
//  inline string_t encode(void const *src, size_t srcSize, unsigned flags, int lineLen = 0, B64_RC *rc = NULL);
//
//  template <typename T, size_t N>
//  inline string_t encode(T (&ar)[N]);
//
//  inline string_t encode(blob_t const &blob);
//
//  inline string_t encode(blob_t const &blob, unsigned flags, int lineLen = 0, B64_RC *rc = NULL);


static void TEST_encode_NULL()
{
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", b64::encode(NULL, 0u));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", b64::encode(NULL, 0u, 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", b64::encode(NULL, 0u, 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", b64::encode(NULL, 0u, 0, -1, NULL));
}

static void TEST_encode_EMPTY()
{
    unsigned int    bytes[1];

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", b64::encode(&bytes[0], 0u));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", b64::encode(&bytes[0], 0u, 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", b64::encode(&bytes[0], 0u, 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", b64::encode(&bytes[0], 0u, 0, -1, NULL));

    b64::blob_t blob;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", b64::encode(blob));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", b64::encode(blob, 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", b64::encode(blob, 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", b64::encode(blob, 0, -1, NULL));
}

static void TEST_encode_1_BYTE_0()
{
    unsigned char   bytes[] = { 0 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AA==", b64::encode(&bytes[0], sizeof(bytes)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AA==", b64::encode(&bytes[0], sizeof(bytes), 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AA==", b64::encode(&bytes[0], sizeof(bytes), 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AA==", b64::encode(&bytes[0], sizeof(bytes), 0, -1, NULL));

    b64::blob_t blob(STLSOFT_NUM_ELEMENTS(bytes));

    std::copy(&bytes[0], &bytes[0] + STLSOFT_NUM_ELEMENTS(bytes), blob.begin());

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AA==", b64::encode(blob));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AA==", b64::encode(blob, 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AA==", b64::encode(blob, 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AA==", b64::encode(blob, 0, -1, NULL));
}

static void TEST_encode_1_BYTE_1()
{
    unsigned char   bytes[] = { 1 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQ==", b64::encode(&bytes[0], sizeof(bytes)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQ==", b64::encode(&bytes[0], sizeof(bytes), 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQ==", b64::encode(&bytes[0], sizeof(bytes), 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQ==", b64::encode(&bytes[0], sizeof(bytes), 0, -1, NULL));

    b64::blob_t blob(STLSOFT_NUM_ELEMENTS(bytes));

    std::copy(&bytes[0], &bytes[0] + STLSOFT_NUM_ELEMENTS(bytes), blob.begin());

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQ==", b64::encode(blob));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQ==", b64::encode(blob, 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQ==", b64::encode(blob, 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQ==", b64::encode(blob, 0, -1, NULL));
}

static void TEST_encode_5_BYTES_ALL_1S()
{
    unsigned char   bytes[] = { 1, 1, 1, 1, 1 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQE=", b64::encode(&bytes[0], sizeof(bytes)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), 0, -1, NULL));

    b64::blob_t blob(STLSOFT_NUM_ELEMENTS(bytes));

    std::copy(&bytes[0], &bytes[0] + STLSOFT_NUM_ELEMENTS(bytes), blob.begin());

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQE=", b64::encode(blob));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQE=", b64::encode(blob, 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQE=", b64::encode(blob, 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQE=", b64::encode(blob, 0, -1, NULL));
}

static void TEST_encode_5_BYTES_1_THEN_2S()
{
    unsigned char   bytes[] = { 1, 2, 2, 2, 2 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQICAgI=", b64::encode(&bytes[0], sizeof(bytes)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQICAgI=", b64::encode(&bytes[0], sizeof(bytes), 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQICAgI=", b64::encode(&bytes[0], sizeof(bytes), 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQICAgI=", b64::encode(&bytes[0], sizeof(bytes), 0, -1, NULL));

    b64::blob_t blob(STLSOFT_NUM_ELEMENTS(bytes));

    std::copy(&bytes[0], &bytes[0] + STLSOFT_NUM_ELEMENTS(bytes), blob.begin());

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQICAgI=", b64::encode(blob));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQICAgI=", b64::encode(blob, 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQICAgI=", b64::encode(blob, 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQICAgI=", b64::encode(blob, 0, -1, NULL));
}

static void TEST_encode_8_BYTES_ALL_1S()
{
    unsigned char   bytes[] = { 1, 1, 1, 1, 1, 1, 1, 1 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), 0, -1, NULL));

    b64::blob_t blob(STLSOFT_NUM_ELEMENTS(bytes));

    std::copy(&bytes[0], &bytes[0] + STLSOFT_NUM_ELEMENTS(bytes), blob.begin());

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQE=", b64::encode(blob));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQE=", b64::encode(blob, 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQE=", b64::encode(blob, 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQE=", b64::encode(blob, 0, -1, NULL));
}

static void TEST_encode_8_BYTES_ASCENDING()
{
    unsigned char   bytes[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQIDBAUGBwg=", b64::encode(&bytes[0], sizeof(bytes)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQIDBAUGBwg=", b64::encode(&bytes[0], sizeof(bytes), 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQIDBAUGBwg=", b64::encode(&bytes[0], sizeof(bytes), 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQIDBAUGBwg=", b64::encode(&bytes[0], sizeof(bytes), 0, -1, NULL));

    b64::blob_t blob(STLSOFT_NUM_ELEMENTS(bytes));

    std::copy(&bytes[0], &bytes[0] + STLSOFT_NUM_ELEMENTS(bytes), blob.begin());

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQIDBAUGBwg=", b64::encode(blob));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQIDBAUGBwg=", b64::encode(blob, 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQIDBAUGBwg=", b64::encode(blob, 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQIDBAUGBwg=", b64::encode(blob, 0, -1, NULL));
}

static void TEST_encode_8_BYTES_LINE_LEN_40()
{
    unsigned char   bytes[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQIDBAUGBwg=", b64::encode(&bytes[0], sizeof(bytes), 0, 40));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQIDBAUGBwg=", b64::encode(&bytes[0], sizeof(bytes), 0, 40, NULL));

    b64::blob_t blob(STLSOFT_NUM_ELEMENTS(bytes));

    std::copy(&bytes[0], &bytes[0] + STLSOFT_NUM_ELEMENTS(bytes), blob.begin());

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQIDBAUGBwg=", b64::encode(blob, 0, 40));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQIDBAUGBwg=", b64::encode(blob, 0, 40, NULL));
}

static void TEST_encode_8_BYTES_LINE_LEN_4()
{
    unsigned char   bytes[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQID\r\nBAUG\r\nBwg=", b64::encode(&bytes[0], sizeof(bytes), 0, 4));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQID\r\nBAUG\r\nBwg=", b64::encode(&bytes[0], sizeof(bytes), 0, 4, NULL));

    b64::blob_t blob(STLSOFT_NUM_ELEMENTS(bytes));

    std::copy(&bytes[0], &bytes[0] + STLSOFT_NUM_ELEMENTS(bytes), blob.begin());

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQID\r\nBAUG\r\nBwg=", b64::encode(blob, 0, 4));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQID\r\nBAUG\r\nBwg=", b64::encode(blob, 0, 4, NULL));
}

static void TEST_encode_80_BYTES_NEGATIVE_LINE_LEN_IS_64()
{
    unsigned char   bytes[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), 0, -1, NULL));

    b64::blob_t blob(STLSOFT_NUM_ELEMENTS(bytes));

    std::copy(&bytes[0], &bytes[0] + STLSOFT_NUM_ELEMENTS(bytes), blob.begin());

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(blob));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(blob, 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(blob, 0, -1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(blob, 0, -1, NULL));
}

static void TEST_encode_80_BYTES_LINE_LEN_64()
{
    unsigned char   bytes[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), b64::B64_F_LINE_LEN_64));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), b64::B64_F_LINE_LEN_64, 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), b64::B64_F_LINE_LEN_64, 0, NULL));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), 0, 64));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), 0, 64, NULL));

    b64::blob_t blob(STLSOFT_NUM_ELEMENTS(bytes));

    std::copy(&bytes[0], &bytes[0] + STLSOFT_NUM_ELEMENTS(bytes), blob.begin());

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(blob));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(blob, b64::B64_F_LINE_LEN_64));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(blob, b64::B64_F_LINE_LEN_64, 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(blob, b64::B64_F_LINE_LEN_64, 0, NULL));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(blob, 0, 64));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(blob, 0, 64, NULL));
}

static void TEST_encode_80_BYTES_LINE_LEN_76()
{
    unsigned char   bytes[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes)));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), b64::B64_F_LINE_LEN_76));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), b64::B64_F_LINE_LEN_76, 0));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), b64::B64_F_LINE_LEN_76, 0, NULL));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), 0, 76));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), 0, 76, NULL));

    b64::blob_t blob(STLSOFT_NUM_ELEMENTS(bytes));

    std::copy(&bytes[0], &bytes[0] + STLSOFT_NUM_ELEMENTS(bytes), blob.begin());

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(blob));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(blob, b64::B64_F_LINE_LEN_76));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(blob, 0, 76));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(blob, 0, 76, NULL));
}

static void TEST_encode_80_BYTES_LINE_LEN_80()
{
    unsigned char   bytes[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), 0, 80));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(&bytes[0], sizeof(bytes), 0, 80, NULL));

    b64::blob_t blob(STLSOFT_NUM_ELEMENTS(bytes));

    std::copy(&bytes[0], &bytes[0] + STLSOFT_NUM_ELEMENTS(bytes), blob.begin());

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(blob, 0, 80));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("AQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEB\r\nAQEBAQEBAQEBAQEBAQEBAQEBAQE=", b64::encode(blob, 0, 80, NULL));
}

static void TEST_encode_1_BYTE_10()
{
    unsigned char   bytes[] = { 10 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("Cg==", b64::encode(&bytes[0], sizeof(bytes)));
}

static void TEST_encode_1_BYTE_100()
{
    unsigned char   bytes[] = { 100 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ZA==", b64::encode(&bytes[0], sizeof(bytes)));
}

static void TEST_encode_1_BYTE_128()
{
    unsigned char   bytes[] = { 128 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("gA==", b64::encode(&bytes[0], sizeof(bytes)));
}

static void TEST_encode_1_BYTE_255()
{
    unsigned char   bytes[] = { 255 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/w==", b64::encode(&bytes[0], sizeof(bytes)));
}

static void TEST_encode_TEXT_STRING()
{
    char bytes[] = "This is a test string";

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("VGhpcyBpcyBhIHRlc3Qgc3RyaW5n", b64::encode(&bytes[0], sizeof(bytes) - 1));
}

static void TEST_encode_15_BYTES_WITH_NEGATIVE_VALUES()
{
    signed char bytes[] = { 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7 };

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("BwYFBAMCAQD//v38+/r5", b64::encode(&bytes[0], sizeof(bytes)));
}

static void TEST_decode_PTR_AND_LEN_UNKNOWN_CHAR_THROWS(void)
{
    using namespace b64;

    char const enc[] = "abcdefg%";

    try
    {
        blob_t r = decode(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u);

        XTESTS_TEST_FAIL("should not reach here");
    }
    catch (b64::coding_exception& x)
    {
        XTESTS_TEST_ENUM_EQUAL(b64::B64_RC_DATA_ERROR, x.get_rc());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, x.get_badChar());
        XTESTS_TEST_CHARACTER_EQUAL('%', *x.get_badChar());
    }
}

static void TEST_decode_NUL_TERMINATED_UNKNOWN_CHAR_THROWS(void)
{
    using namespace b64;

    char const enc[] = "abcdefg%";

    try
    {
        blob_t r = decode(enc);

        XTESTS_TEST_FAIL("should not reach here");
    }
    catch (b64::coding_exception& x)
    {
        XTESTS_TEST_ENUM_EQUAL(b64::B64_RC_DATA_ERROR, x.get_rc());
        XTESTS_TEST_POINTER_EQUAL(NULL, x.get_badChar());
    }
}

static void TEST_decode_NUL_TERMINATED_STOP_ON_NOTHING_DOES_NOT_THROW(void)
{
    using namespace b64;

    char const enc[] = "abcdefg%";

    try
    {
        blob_t r = decode(B64_F_STOP_ON_NOTHING, enc);

        XTESTS_TEST_PASSED();
    }
    catch (b64::coding_exception& /* x */)
    {
        XTESTS_TEST_FAIL("should not reach here");
    }
}

static void TEST_decode_SIMPLE_STRING_UNKNOWN_CHAR_THROWS(void)
{
    using namespace b64;

    stlsoft::simple_string const enc = "abcdefg%";

    try
    {
        blob_t r = decode(enc);

        XTESTS_TEST_FAIL("should not reach here");
    }
    catch (b64::coding_exception& x)
    {
        XTESTS_TEST_ENUM_EQUAL(b64::B64_RC_DATA_ERROR, x.get_rc());
        XTESTS_TEST_POINTER_EQUAL(NULL, x.get_badChar());
    }
}

static void TEST_decode_SIMPLE_STRING_STOP_ON_NOTHING_DOES_NOT_THROW(void)
{
    using namespace b64;

    stlsoft::simple_string const enc = "abcdefg%";

    try
    {
        blob_t r = decode(B64_F_STOP_ON_NOTHING, enc);

        XTESTS_TEST_PASSED();
    }
    catch (b64::coding_exception& /* x */)
    {
        XTESTS_TEST_FAIL("should not reach here");
    }
}

static void TEST_decode_STRING_T_UNKNOWN_CHAR_THROWS(void)
{
    using namespace b64;

    string_t const enc = "abcdefg%";

    try
    {
        blob_t r = decode(enc);

        XTESTS_TEST_FAIL("should not reach here");
    }
    catch (b64::coding_exception& x)
    {
        XTESTS_TEST_ENUM_EQUAL(b64::B64_RC_DATA_ERROR, x.get_rc());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, x.get_badChar());
        XTESTS_TEST_CHARACTER_EQUAL('%', *x.get_badChar());
    }
}

static void TEST_decode_STRING_T_AND_FLAGS_STOP_ON_NOTHING_DOES_NOT_THROW(void)
{
    using namespace b64;

    string_t const enc = "abcdefg%";

    try
    {
        blob_t r = decode(enc, B64_F_STOP_ON_NOTHING);

        XTESTS_TEST_PASSED();
    }
    catch (b64::coding_exception& /* x */)
    {
        XTESTS_TEST_FAIL("should not reach here");
    }
}

static void TEST_decode_FLAGS_AND_STRING_T_STOP_ON_NOTHING_DOES_NOT_THROW(void)
{
    using namespace b64;

    string_t const enc = "abcdefg%";

    try
    {
        blob_t r = decode(B64_F_STOP_ON_NOTHING, enc);

        XTESTS_TEST_PASSED();
    }
    catch (b64::coding_exception& /* x */)
    {
        XTESTS_TEST_FAIL("should not reach here");
    }
}

static void TEST_decode_STRING_T_STOP_ON_BAD_CHAR_REPORTS_BADCHAR_AND_RC(void)
{
    using namespace b64;

    string_t const enc = "abcdefg%";

    try
    {
        b64_char_t const*   badChar =   NULL;
        B64_RC              rc      =   B64_RC_OK;

        blob_t r = decode(enc, B64_F_STOP_ON_BAD_CHAR, &badChar, &rc);

        XTESTS_TEST_INTEGER_EQUAL(0u, r.size());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, badChar);
        XTESTS_TEST_CHARACTER_EQUAL('%', *badChar);
        XTESTS_TEST_ENUM_EQUAL(B64_RC_DATA_ERROR, rc);
    }
    catch (b64::coding_exception& /* x */)
    {
        XTESTS_TEST_FAIL("should not reach here");
    }
}

static void TEST_decode_PTR_AND_LEN_STOP_ON_BAD_CHAR_REPORTS_BADCHAR_AND_RC(void)
{
    using namespace b64;

    char const enc[] = "abcdefg%";

    try
    {
        b64_char_t const*   badChar =   NULL;
        B64_RC              rc      =   B64_RC_OK;

        blob_t r = decode(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u, B64_F_STOP_ON_BAD_CHAR, &badChar, &rc);

        XTESTS_TEST_INTEGER_EQUAL(0u, r.size());
        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, badChar);
        XTESTS_TEST_CHARACTER_EQUAL('%', *badChar);
        XTESTS_TEST_ENUM_EQUAL(B64_RC_DATA_ERROR, rc);
    }
    catch (b64::coding_exception& /* x */)
    {
        XTESTS_TEST_FAIL("should not reach here");
    }
}

static void TEST_decode_PTR_AND_LEN_STOP_ON_BAD_CHAR_THROWS_WITH_BADCHAR(void)
{
    using namespace b64;

    char const enc[] = "abcdefg%";

    b64_char_t const*   badChar =   NULL;

    try
    {
        blob_t r = decode(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u, B64_F_STOP_ON_BAD_CHAR, &badChar);

        XTESTS_TEST_FAIL("should not reach here");
    }
    catch (b64::coding_exception& x)
    {
        XTESTS_TEST_ENUM_EQUAL(b64::B64_RC_DATA_ERROR, x.get_rc());
        XTESTS_TEST_POINTER_EQUAL(NULL, x.get_badChar());
        XTESTS_TEST_CHARACTER_EQUAL('%', *badChar);
    }
}
} /* anonymous namespace */

/* ///////////////////////////// end of file //////////////////////////// */

