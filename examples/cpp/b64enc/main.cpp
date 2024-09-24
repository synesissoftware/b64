
/* b64 header files */
#include <b64/b64.hpp>

/* C++ standard header files */
#include <iostream>
#include <string>

/* C standard header files */
#include <stdio.h>
#include <string.h>




void encode_input(char const* input_string)
{
    size_t const len = ::strlen(input_string);

    std::string const r = b64::encode(input_string, len);

    std::cout
        << "input-string '"
        << input_string
        << "' ("
        << len
        << " byte(s)) converted to base-64 obtains '"
        << r
        << "' ("
        << r.length()
        << " char(s))"
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

    try
    {
        char const* const input_string = argv[1];

        encode_input(input_string);

        return EXIT_SUCCESS;
    }
    catch (std::bad_alloc&)
    {
        fprintf(stderr, "%s: out of memory\n", argv[0]);
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

