
/* b64 header files */
#include <b64/b64.hpp>

/* STLSoft header files */
#include <stlsoft/memory/auto_buffer.hpp>
#include <stlsoft/conversion/byte_format_functions.hpp>

/* C++ standard header files */
#include <iostream>

/* C standard header files */
#include <stdio.h>
#include <string.h>


void decode_input(char const* input_string)
{
    size_t const        len = ::strlen(input_string);
    b64::blob_t const   r = b64::decode(input_string, len);

    stlsoft::auto_buffer<char, 100> buff(0);

    size_t const        n   =   stlsoft::format_bytes(r.data(), r.size(), NULL, 0, 1, " ", 8, "\n");

    buff.resize(n + 1);

    stlsoft::format_bytes(r.data(), r.size(), &buff[0], buff.size(), 1, " ", 8, "\n");
    buff[n] = '\0';

    std::cout
        << "input-string '"
        << input_string
        << "' ("
        << len
        << " char(s)) converted to base-64 obtains '\n"
        << buff.data()
        << "\n' ("
        << r.size()
        << " byte(s))"
        << std::endl;
}

int main(int argc, char* argv[])
{
    // check if "--help" flag specified

    for (int i = 1; i != argc; ++i)
    {
        if (0 == ::strcmp(argv[i], "--help"))
        {
            std::cout
                << "USAGE: "
                << argv[0]
                << " { <input-string> | --help }"
                << std::endl;

            return EXIT_SUCCESS;
        }
    }

    // ensure only a single value argument is specified

    switch (argc)
    {
    case 1:

        std::cerr << "input not specified; use --help for usage" << std::endl;

        return EXIT_FAILURE;
    case 2:

        break;
    default:

        std::cerr << "too many arguments; use --help for usage" << std::endl;

        return EXIT_FAILURE;
    }

    // do encoding (wrapped in exception-handling as would be done in a real
    // program)

    char const* const input_string = argv[1];

    try
    {
        decode_input(input_string);

        return EXIT_SUCCESS;
    }
    catch (std::bad_alloc&)
    {
        fprintf(stderr, "%s: out of memory\n", argv[0]);
    }
    catch (b64::coding_exception& x)
    {
        std::cerr
            << argv[0]
            << " failed to decode '"
            << input_string
            << "': "
            << x.what()
            << std::endl;
    }
    catch (std::exception& x)
    {
        std::cerr
            << argv[0]
            << " exception: "
            << x.what()
            << std::endl;
    }

    return EXIT_FAILURE;
}


/* ///////////////////////////// end of file //////////////////////////// */

