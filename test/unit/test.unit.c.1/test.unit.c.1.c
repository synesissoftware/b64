/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.c.1.c
 *
 * Purpose: Implementation file for the test.unit.c.1 project.
 *
 * Created: 21st April 2009
 * Updated: 24th September 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <b64/b64.h>


/* /////////////////////////////////////////////////////////////////////////
 * includes
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

static void test_1_00(void);
static void test_1_01(void);
static void test_1_02(void);
static void test_1_03(void);
static void test_1_04(void);
static void test_1_05(void);
static void test_1_06(void);
static void test_1_07(void);
static void test_1_08(void);
static void test_1_09(void);

static void test_2_00(void);
static void test_2_01(void);
static void test_2_02(void);
static void test_2_03(void);
static void test_2_04(void);
static void test_2_05(void);
static void test_2_06(void);
static void test_2_07(void);
static void test_2_08(void);
static void test_2_09(void);


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.c.1", verbosity))
    {
        XTESTS_RUN_CASE(test_1_00);
        XTESTS_RUN_CASE(test_1_01);
        XTESTS_RUN_CASE(test_1_02);
        XTESTS_RUN_CASE(test_1_03);
        XTESTS_RUN_CASE(test_1_04);
        XTESTS_RUN_CASE(test_1_05);
        XTESTS_RUN_CASE(test_1_06);
        XTESTS_RUN_CASE(test_1_07);
        XTESTS_RUN_CASE(test_1_08);
        XTESTS_RUN_CASE(test_1_09);

        XTESTS_RUN_CASE(test_2_00);
        XTESTS_RUN_CASE(test_2_01);
        XTESTS_RUN_CASE(test_2_02);
        XTESTS_RUN_CASE(test_2_03);
        XTESTS_RUN_CASE(test_2_04);
        XTESTS_RUN_CASE(test_2_05);
        XTESTS_RUN_CASE(test_2_06);
        XTESTS_RUN_CASE(test_2_07);
        XTESTS_RUN_CASE(test_2_08);
        XTESTS_RUN_CASE(test_2_09);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_1_00(void)
{
    XTESTS_TEST_INTEGER_EQUAL(0u, b64_encode(NULL, 0, NULL, 0));
}

static void test_1_01(void)
{
    unsigned char   bytes[] = { 0 };
    char            result[1001];

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), NULL, 0));

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), &result[0], STLSOFT_NUM_ELEMENTS(result)));
    result[1000] = '\0';
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("AA==", result, 4u);
}

static void test_1_02(void)
{
    unsigned char   bytes[] = { 1 };
    char            result[1001];

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), NULL, 0));

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), &result[0], STLSOFT_NUM_ELEMENTS(result)));
    result[1000] = '\0';
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("AQ==", result, 4u);
}

static void test_1_03(void)
{
    unsigned char   bytes[] = { 10 };
    char            result[1001];

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), NULL, 0));

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), &result[0], STLSOFT_NUM_ELEMENTS(result)));
    result[1000] = '\0';
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("Cg==", result, 4u);
}

static void test_1_04(void)
{
    unsigned char   bytes[] = { 100 };
    char            result[1001];

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), NULL, 0));

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), &result[0], STLSOFT_NUM_ELEMENTS(result)));
    result[1000] = '\0';
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("ZA==", result, 4u);
}

static void test_1_05(void)
{
    unsigned char   bytes[] = { 128 };
    char            result[1001];

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), NULL, 0));

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), &result[0], STLSOFT_NUM_ELEMENTS(result)));
    result[1000] = '\0';
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("gA==", result, 4u);
}

static void test_1_06(void)
{
    unsigned char   bytes[] = { 255 };
    char            result[1001];

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), NULL, 0));

    XTESTS_TEST_INTEGER_EQUAL(4u, b64_encode(&bytes[0], sizeof(bytes), &result[0], STLSOFT_NUM_ELEMENTS(result)));
    result[1000] = '\0';
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("/w==", result, 4u);
}

static void test_1_07(void)
{
    char            bytes[] = "This is a test string";
    char            result[1001];

    XTESTS_TEST_INTEGER_EQUAL(28u, b64_encode(&bytes[0], sizeof(bytes) - 1, NULL, 0));

    XTESTS_TEST_INTEGER_EQUAL(28u, b64_encode(&bytes[0], sizeof(bytes) - 1, &result[0], STLSOFT_NUM_ELEMENTS(result)));
    result[1000] = '\0';
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("VGhpcyBpcyBhIHRlc3Qgc3RyaW5n", result, 28u);
}

static void test_1_08(void)
{
    signed char bytes[] = { 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7 };
    char        result[1001];

    XTESTS_TEST_INTEGER_EQUAL(20u, b64_encode(&bytes[0], sizeof(bytes), NULL, 0));

    XTESTS_TEST_INTEGER_EQUAL(20u, b64_encode(&bytes[0], sizeof(bytes), &result[0], STLSOFT_NUM_ELEMENTS(result)));
    result[1000] = '\0';
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("BwYFBAMCAQD//v38+/r5", result, 20u);
}

static void test_1_09(void)
{
}




static void test_2_00(void)
{
    char const      enc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ=";
    unsigned char   bytes[10];
    B64_RC          rc  =   B64_RC_OK;
    size_t          n   =   b64_decode2(enc, STLSOFT_NUM_ELEMENTS(enc) - 1u, &bytes[0], sizeof(bytes), 0, NULL, &rc);

    XTESTS_TEST_INTEGER_EQUAL(0u, n);
    XTESTS_TEST_ENUM_EQUAL(B64_RC_INSUFFICIENT_BUFFER, rc);
}

static void test_2_01(void)
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

static void test_2_02(void)
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

        /* TODO: change 3 -> 1 when incorporate GH fix */
        XTESTS_TEST_INTEGER_EQUAL(3, n);
    }
}

static void test_2_03(void)
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

        /* TODO: change 3 -> 2 when incorporate GH fix */
        XTESTS_TEST_INTEGER_EQUAL(3, n);
    }
}

static void test_2_04(void)
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

static void test_2_05(void)
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

        /* TODO: change 21 -> 20 when incorporate GH fix */
        XTESTS_TEST_INTEGER_EQUAL(21, n);
    }
}

static void test_2_06(void)
{
}

static void test_2_07(void)
{
}

static void test_2_08(void)
{
}

static void test_2_09(void)
{
}


/* ///////////////////////////// end of file //////////////////////////// */

