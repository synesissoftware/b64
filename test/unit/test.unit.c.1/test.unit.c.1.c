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

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
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
}

static void test_2_02(void)
{
}

static void test_2_03(void)
{
}

static void test_2_04(void)
{
}

static void test_2_05(void)
{
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

