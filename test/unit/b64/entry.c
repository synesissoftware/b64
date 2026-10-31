/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/b64/entry.c
 *
 * Purpose: Implementation file for the test.unit.b64 project.
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

#include <b64/b64.h>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void TEST_b64_encode_NULL_AND_EMPTY(void);
static void TEST_b64_encode_SINGLE_BYTE_0(void);
static void TEST_b64_encode_SINGLE_BYTE_1(void);
static void TEST_b64_encode_SINGLE_BYTE_10(void);
static void TEST_b64_encode_SINGLE_BYTE_100(void);
static void TEST_b64_encode_SINGLE_BYTE_128(void);
static void TEST_b64_encode_SINGLE_BYTE_255(void);
static void TEST_b64_encode_TEXT_STRING(void);
static void TEST_b64_encode_15_BYTES_WITH_NEGATIVE_VALUES(void);

static void TEST_b64_decode2_INSUFFICIENT_BUFFER(void);
static void TEST_b64_decode2_NULL_AND_EMPTY(void);
static void TEST_b64_decode2_TWO_PADDING_CHARACTERS(void);
static void TEST_b64_decode2_ONE_PADDING_CHARACTER(void);
static void TEST_b64_decode2_NO_PADDING(void);
static void TEST_b64_decode2_GERRY_HORNBILL_EXAMPLE(void);
static void TEST_b64_decode2_DOUBLE_PADDING_ONLY(void);
static void TEST_b64_decode2_SINGLE_PADDING_ONLY(void);


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
        XTESTS_RUN_CASE(TEST_b64_encode_NULL_AND_EMPTY);
        XTESTS_RUN_CASE(TEST_b64_encode_SINGLE_BYTE_0);
        XTESTS_RUN_CASE(TEST_b64_encode_SINGLE_BYTE_1);
        XTESTS_RUN_CASE(TEST_b64_encode_SINGLE_BYTE_10);
        XTESTS_RUN_CASE(TEST_b64_encode_SINGLE_BYTE_100);
        XTESTS_RUN_CASE(TEST_b64_encode_SINGLE_BYTE_128);
        XTESTS_RUN_CASE(TEST_b64_encode_SINGLE_BYTE_255);
        XTESTS_RUN_CASE(TEST_b64_encode_TEXT_STRING);
        XTESTS_RUN_CASE(TEST_b64_encode_15_BYTES_WITH_NEGATIVE_VALUES);

        XTESTS_RUN_CASE(TEST_b64_decode2_INSUFFICIENT_BUFFER);
        XTESTS_RUN_CASE(TEST_b64_decode2_NULL_AND_EMPTY);
        XTESTS_RUN_CASE(TEST_b64_decode2_TWO_PADDING_CHARACTERS);
        XTESTS_RUN_CASE(TEST_b64_decode2_ONE_PADDING_CHARACTER);
        XTESTS_RUN_CASE(TEST_b64_decode2_NO_PADDING);
        XTESTS_RUN_CASE(TEST_b64_decode2_GERRY_HORNBILL_EXAMPLE);
        XTESTS_RUN_CASE(TEST_b64_decode2_DOUBLE_PADDING_ONLY);
        XTESTS_RUN_CASE(TEST_b64_decode2_SINGLE_PADDING_ONLY);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void TEST_b64_encode_NULL_AND_EMPTY(void)
{
    XTESTS_TEST_INTEGER_EQUAL(0u, b64_encode(NULL, 0, NULL, 0));
}

static void TEST_b64_encode_SINGLE_BYTE_0(void)
{
    unsigned char   bytes[] = { 0 };
    char            result[1001];

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), NULL, 0));

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), &result[0], STLSOFT_NUM_ELEMENTS(result)));
    result[1000] = '\0';
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("AA==", result, 4u);
}

static void TEST_b64_encode_SINGLE_BYTE_1(void)
{
    unsigned char   bytes[] = { 1 };
    char            result[1001];

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), NULL, 0));

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), &result[0], STLSOFT_NUM_ELEMENTS(result)));
    result[1000] = '\0';
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("AQ==", result, 4u);
}

static void TEST_b64_encode_SINGLE_BYTE_10(void)
{
    unsigned char   bytes[] = { 10 };
    char            result[1001];

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), NULL, 0));

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), &result[0], STLSOFT_NUM_ELEMENTS(result)));
    result[1000] = '\0';
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("Cg==", result, 4u);
}

static void TEST_b64_encode_SINGLE_BYTE_100(void)
{
    unsigned char   bytes[] = { 100 };
    char            result[1001];

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), NULL, 0));

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), &result[0], STLSOFT_NUM_ELEMENTS(result)));
    result[1000] = '\0';
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("ZA==", result, 4u);
}

static void TEST_b64_encode_SINGLE_BYTE_128(void)
{
    unsigned char   bytes[] = { 128 };
    char            result[1001];

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), NULL, 0));

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), &result[0], STLSOFT_NUM_ELEMENTS(result)));
    result[1000] = '\0';
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("gA==", result, 4u);
}

static void TEST_b64_encode_SINGLE_BYTE_255(void)
{
    unsigned char   bytes[] = { 255 };
    char            result[1001];

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), NULL, 0));

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), &result[0], STLSOFT_NUM_ELEMENTS(result)));
    result[1000] = '\0';
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("/w==", result, 4u);
}

static void TEST_b64_encode_TEXT_STRING(void)
{
    char            bytes[] = "This is a test string";
    char            result[1001];

    XTESTS_TEST_INTEGER_EQUAL(28u, b64_encode(&bytes[0], sizeof(bytes) - 1, NULL, 0));

    XTESTS_TEST_INTEGER_EQUAL(28u, b64_encode(&bytes[0], sizeof(bytes) - 1, &result[0], STLSOFT_NUM_ELEMENTS(result)));
    result[1000] = '\0';
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("VGhpcyBpcyBhIHRlc3Qgc3RyaW5n", result, 28u);
}

static void TEST_b64_encode_15_BYTES_WITH_NEGATIVE_VALUES(void)
{
    signed char bytes[] = { 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7 };
    char        result[1001];

    XTESTS_TEST_INTEGER_EQUAL(20u, b64_encode(&bytes[0], sizeof(bytes), NULL, 0));

    XTESTS_TEST_INTEGER_EQUAL(20u, b64_encode(&bytes[0], sizeof(bytes), &result[0], STLSOFT_NUM_ELEMENTS(result)));
    result[1000] = '\0';
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("BwYFBAMCAQD//v38+/r5", result, 20u);
}


static void TEST_b64_decode2_INSUFFICIENT_BUFFER(void)
{
    char const      enc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ=";
    unsigned char   bytes[10];
    B64_RC          rc  =   B64_RC_OK;
    size_t          n   =   b64_decode2(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u, &bytes[0], sizeof(bytes), 0, NULL, &rc);

    XTESTS_TEST_INTEGER_EQUAL(0u, n);
    XTESTS_TEST_ENUM_EQUAL(B64_RC_INSUFFICIENT_BUFFER, rc);
}

static void TEST_b64_decode2_NULL_AND_EMPTY(void)
{
    char const* const   enc = NULL;

    {
        char            dec[10];
        B64_RC          rc  =   B64_RC_OK;
        size_t const    n   =   b64_decode2(enc, 0, dec, sizeof(dec), 0, NULL, &rc);

        dec[n] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(0, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", dec);
    }

    {
        B64_RC          rc  =   B64_RC_OK;
        size_t const    n   =   b64_decode2(enc, 0, NULL, 0, 0, NULL, &rc);

        XTESTS_TEST_INTEGER_EQUAL(0, n);
    }
}

static void TEST_b64_decode2_TWO_PADDING_CHARACTERS(void)
{
    char const      enc[] = "MA==";

    {
        char            dec[10];
        B64_RC          rc  =   B64_RC_OK;
        size_t const    n   =   b64_decode2(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u, dec, sizeof(dec), 0, NULL, &rc);

        dec[n] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(1, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0", dec);
    }

    {
        B64_RC          rc  =   B64_RC_OK;
        size_t const    n   =   b64_decode2(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u, NULL, 0, 0, NULL, &rc);

        XTESTS_TEST_INTEGER_EQUAL(1, n);
    }
}

static void TEST_b64_decode2_ONE_PADDING_CHARACTER(void)
{
    char const      enc[] = "MDA=";

    {
        char            dec[10];
        B64_RC          rc  =   B64_RC_OK;
        size_t const    n   =   b64_decode2(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u, dec, sizeof(dec), 0, NULL, &rc);

        dec[n] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(2, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("00", dec);
    }

    {
        B64_RC          rc  =   B64_RC_OK;
        size_t const    n   =   b64_decode2(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u, NULL, 0, 0, NULL, &rc);

        XTESTS_TEST_INTEGER_EQUAL(2, n);
    }
}

static void TEST_b64_decode2_NO_PADDING(void)
{
    char const      enc[] = "MDAw";

    {
        char            dec[10];
        B64_RC          rc  =   B64_RC_OK;
        size_t const    n   =   b64_decode2(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u, dec, sizeof(dec), 0, NULL, &rc);

        dec[n] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(3, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("000", dec);
    }

    {
        B64_RC          rc  =   B64_RC_OK;
        size_t const    n   =   b64_decode2(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u, NULL, 0, 0, NULL, &rc);

        XTESTS_TEST_INTEGER_EQUAL(3, n);
    }
}

static void TEST_b64_decode2_GERRY_HORNBILL_EXAMPLE(void)
{
    // This is gerry-hornbill's example, which should obtain 20 characters

    char const      enc[] = "VGhlIHN0cmluZyB0byBlbmNvZGU=";

    {
        char            dec[21];
        B64_RC          rc  =   B64_RC_OK;
        size_t const    n   =   b64_decode2(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u, dec, sizeof(dec), 0, NULL, &rc);

        dec[n] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(20, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("The string to encode", dec);
    }

    {
        B64_RC          rc  =   B64_RC_OK;
        size_t const    n   =   b64_decode2(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u, NULL, 0, 0, NULL, &rc);

        XTESTS_TEST_INTEGER_EQUAL(20, n);
    }
}

static void TEST_b64_decode2_DOUBLE_PADDING_ONLY(void)
{
    /* padding-only input, shorter than a quantum: the calculated size must
     * not underflow
     */

    char const      enc[] = "==";

    {
        B64_RC          rc  =   B64_RC_OK;
        size_t const    n   =   b64_decode2(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u, NULL, 0, 0, NULL, &rc);

        XTESTS_TEST_INTEGER_EQUAL(0u, n);
        XTESTS_TEST_ENUM_EQUAL(B64_RC_OK, rc);
    }

    {
        unsigned char   dec[10];
        B64_RC          rc  =   B64_RC_OK;
        size_t const    n   =   b64_decode2(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u, &dec[0], sizeof(dec), 0, NULL, &rc);

        XTESTS_TEST_INTEGER_EQUAL(0u, n);
        XTESTS_TEST_ENUM_EQUAL(B64_RC_OK, rc);
    }
}

static void TEST_b64_decode2_SINGLE_PADDING_ONLY(void)
{
    /* a single padding character */

    char const      enc[] = "=";

    {
        B64_RC          rc  =   B64_RC_OK;
        size_t const    n   =   b64_decode2(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u, NULL, 0, 0, NULL, &rc);

        XTESTS_TEST_INTEGER_EQUAL(0u, n);
        XTESTS_TEST_ENUM_EQUAL(B64_RC_OK, rc);
    }

    {
        unsigned char   dec[10];
        B64_RC          rc  =   B64_RC_OK;
        size_t const    n   =   b64_decode2(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u, &dec[0], sizeof(dec), 0, NULL, &rc);

        XTESTS_TEST_INTEGER_EQUAL(0u, n);
        XTESTS_TEST_ENUM_EQUAL(B64_RC_OK, rc);
    }
}

/* ///////////////////////////// end of file //////////////////////////// */

