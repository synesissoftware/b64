/* /////////////////////////////////////////////////////////////////////////
 * File:        example.cpp.1.cpp
 *
 * Purpose:     Illustrates encoding and decoding of array of bytes (using
 *              C++ API).
 *
 * Created:     27th April 2006
 * Updated:     23rd December 2023
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

/* ////////////////////////////////////////////////////////////////////// */

int main(int /* argc */, char ** /*argv*/)
{
    /* Simple conversion using encode() and decode(). */

    try
    {
        /* Declare an array of bytes to use as the 'binary' blob to encode. */
        unsigned char   bytes[]  =   { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        /* Print out the bytes to be encoded.
         */
        std::cout << "Encoding " << STLSOFT_NUM_ELEMENTS(bytes) << " bytes:\n";
        std::copy(  bytes, bytes + STLSOFT_NUM_ELEMENTS(bytes)
                ,   stlsoft::FILE_iterator<unsigned char, char>(stdout, " %d"));
        std::cout << std::endl;

        /* Perform the encoding, whose results are returned in an instance of
         * b64::cpp::string_t.
         */
        b64::cpp::string_t  enc =   b64::cpp::encode(&bytes[0], sizeof(bytes));

        std::cout << "Encoded form: [" << enc << "]" << std::endl;

        /* Perform the decoding, whose results are returned in an instance of
         * b64::cpp::blob_t.
         */
        b64::cpp::blob_t    dec =   b64::cpp::decode(enc);

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
    catch(b64::cpp::coding_exception &x)
    {
        std::cerr << "Exception: " << x.what() << std::endl;
    }

    return EXIT_SUCCESS;
}

/* ///////////////////////////// end of file //////////////////////////// */

