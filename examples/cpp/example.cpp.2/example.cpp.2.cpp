/* /////////////////////////////////////////////////////////////////////////
 * File:    example.cpp.2.cpp
 *
 * Purpose: Illustrates encoding and decoding of array of bytes with flags
 *          and custom line-length (using C++ API).
 *
 * Created: 27th April 2006
 * Updated: 24th September 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* b64 Header Files */
#include <b64/b64.hpp>

/* STLSoft C++ Header Files */
#include <stlsoft/stlsoft.h>                    /* If you can't see this file, d/l latest STLSoft 1.9+ from http://www.stlsoft.org/ */
#include <stlsoft/iterator/FILE_iterator.hpp>   /* If you can't see this file, d/l STLSoft 1.10+ or STLSoft 1.10 alpha (for use with STLSoft 1.9), from http://www.stlsoft.org/ */

/* Standard C++ Header Files */
#include <exception>
#include <iostream>

/* Standard C Header Files */
#include <assert.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /* argc */, char ** /*argv*/)
{
    /* Conversion using encode() and decode(), with encoding flags. */

    try
    {
        /* Flags that will control the conversions. */
        unsigned  encodingFlags   =   b64::B64_F_LINE_LEN_USE_PARAM;      /* encode() will use the lineLen parameter to determine line length. */
        unsigned  decodingFlags   =   b64::B64_F_STOP_ON_UNKNOWN_CHAR;    /* decode() will fail if any non-b64-character / non-white-space character is in the encoded string. */
        int       encodingLineLen =   4;                                  /* Encoding line length will be 4 characters. */

        /* Declare an array of bytes to use as the 'binary' blob to encode. */
        unsigned char   bytes[]  =   { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        /* Print out the bytes to be encoded.
         */
        std::cout << "Encoding " << STLSOFT_NUM_ELEMENTS(bytes) << " bytes with specific line-length:\n";
        std::copy(  bytes, bytes + STLSOFT_NUM_ELEMENTS(bytes)
                ,   stlsoft::FILE_iterator<unsigned char>(stdout, " %d"));
        std::cout << std::endl;

        /* Perform the encoding, whose results are returned in an instance of
         * b64::cpp::string_t.
         */
        b64::cpp::string_t  enc =   b64::cpp::encode(&bytes[0], sizeof(bytes), encodingFlags, encodingLineLen);

        std::cout << "Encoded form: [" << enc << "]" << std::endl;

        /* Perform the decoding, whose results are returned in an instance of
         * b64::cpp::blob_t.
         */
        b64::cpp::blob_t    dec =   b64::cpp::decode(enc, decodingFlags);

        /* Verify that the decoding is exactly the same size and contents as
         * the encoding, and then print out the decoded bytes.
         */
        assert(sizeof(bytes) == dec.size());
        assert(0 == ::memcmp(&bytes[0], &dec[0], sizeof(bytes)));

        std::cout << "Decoded into " << STLSOFT_NUM_ELEMENTS(bytes) << " bytes:\n";
        std::copy(  dec.begin(), dec.end()
                ,   stlsoft::FILE_iterator<unsigned char, char>(stdout, " %d"));
        std::cout << std::endl;
    }
    catch (b64::cpp::coding_exception &x)
    {
        std::cerr << "Exception: " << x.what() << std::endl;
    }

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

