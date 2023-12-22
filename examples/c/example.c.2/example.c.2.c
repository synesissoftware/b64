/* /////////////////////////////////////////////////////////////////////////
 * File:        example.c.2.c
 *
 * Purpose:     Illustrates encoding and decoding of array of bytes with
 *              flags and custom line-length (using C API).
 *
 * Created:     27th April 2006
 * Updated:     23rd December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* b64 Header Files */
#include <b64/b64.h>

/* Standard C Header Files */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifndef NUM_ELEMENTS
# define NUM_ELEMENTS(x)        (sizeof(x) / sizeof(0[x]))
#endif /* !NUM_ELEMENTS */

/* ////////////////////////////////////////////////////////////////////// */

int main(void)
{
    /* Conversion using b64_encode2() and b64_decode2(), using a line limit. */

    /* Flags that will control the conversions. */
    const unsigned  encodingFlags   =   B64_F_LINE_LEN_USE_PARAM;   /* b64_encode2() will use the lineLen parameter to determine line length. */
    const unsigned  decodingFlags   =   B64_F_STOP_ON_UNKNOWN_CHAR; /* b64_decode2() will fail if any non-b64-character / non-white-space character is in the encoded string. */
    const int       encodingLineLen =   4;                          /* Encoding line length will be 4 characters. */

    /* Declare an array of bytes to use as the 'binary' blob to encode. */
    unsigned char   bytes[]  =   { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    /* Invoke b64_encode() to determine the maximum size of the encoded
     * string, specifying the argument 0 for the destSize parameter.
     *
     * Note: The value returned may be larger than the actual size
     * required, but will never be smaller.
     */
    B64_RC  rc;
    size_t  cch     =   b64_encode2(&bytes[0], sizeof(bytes), NULL, 0, encodingFlags, encodingLineLen, &rc);

    /* Using the length determined by the call to b64_encode(), create
     * a buffer of sufficient size.
     */
    char        *enc    =   (char*)malloc(cch);
    size_t      cb;
    void        *dec;
    char const  *badChar;
    size_t      i;

    printf("Converting %u bytes:\n", (unsigned)NUM_ELEMENTS(bytes));
    for (i = 0; i != NUM_ELEMENTS(bytes); ++i)
    {
        printf(" %d", bytes[i]);
    }
    puts("");

    /* Perform the encoding. */
    cch = b64_encode2(&bytes[0], sizeof(bytes), enc, cch, encodingFlags, encodingLineLen, &rc);

    printf("Encoded form: [%.*s]\n", (int)cch, enc);

    /* Invoke b64_decode() to determine the maximum size of the decoded
     * blob, specifying the argument 0 for the destLen parameter.
     *
     * Note: The value returned may be larger than the actual size
     * required, but will never be smaller.
     */
    cb = b64_decode2(enc, cch, NULL, 0, decodingFlags, &badChar, &rc);

    /* Using the length determined by the call to b64_decode(), create
     * a buffer of sufficient size.
     */
    dec =   malloc(cb);

    /* Perform the decoding. */
    cb = b64_decode2(enc, cch, dec, cb, decodingFlags, &badChar, &rc);

    /* Handle the error. */
    if (0 == cb)
    {
        fprintf(stderr, "decoding error %u at character %d: %s\n", rc, (int)(badChar - enc), badChar);
    }
    else
    {
        /* Verify that the decoding is exactly the same size and contents as
         * the encoding.
         */
        assert(cb == sizeof(bytes));
        assert(0 == memcmp(&bytes[0], dec, sizeof(bytes)));
    }

    /* Clean up */
    free(dec);
    free(enc);

    return EXIT_SUCCESS;
}

/* ///////////////////////////// end of file //////////////////////////// */

