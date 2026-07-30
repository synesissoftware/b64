# b64 - FAQ <!-- omit in toc -->

The FAQ list is under (constant) development. If you post a question on the
Issues forum (https://github.com/synesissoftware/b64/issues)
it will be used to create one.


## Table of Contents <!-- omit in toc -->

- [Q1: "How do I build b64?"](#q1-how-do-i-build-b64)
- [Q2: "How do I install b64?"](#q2-how-do-i-install-b64)
- [Q3: "How do I use b64?"](#q3-how-do-i-use-b64)


# FAQs: <!-- omit in toc -->

## Q1: "How do I build b64?"

See [INSTALL.md](./INSTALL.md) for the recommended **CMake** flow
(**prepare_cmake.sh**, then **build_cmake.sh**).

For a minimal **C API**-only build with no external dependencies:

```bash
$ ./prepare_cmake.sh --no-cpp --disable-testing -m
```

For a full build (including the **C++ API** and tests), install **STLSoft**
1.11 and **xTests** first, then:

```bash
$ ./prepare_cmake.sh -m
```

Execute `$ ./prepare_cmake.sh --help` for the full set of options.


## Q2: "How do I install b64?"

See [INSTALL.md](./INSTALL.md) for details of how to install **b64**.


## Q3: "How do I use b64?"

Include **b64/b64.h** and link against **libb64** (the **CMake** target is
`b64::core`). Encode and decode with `b64_encode()` / `b64_decode()` (or the
`2`-suffixed variants for flags and status codes).

A minimal sketch:

```c
#include <b64/b64.h>

#include <stdlib.h>

void example(void)
{
    unsigned char const bytes[] = { 1, 2, 3, 4 };
    size_t const cch = b64_encode(bytes, sizeof(bytes), NULL, 0);
    char* const enc = (char*)malloc(cch);

    if (NULL != enc)
    {
        b64_encode(bytes, sizeof(bytes), enc, cch);
        /* ... use enc[0 .. cch) ... */
        free(enc);
    }
}
```

Worked examples live under **examples/c/** and **examples/cpp/**. The **C++
API** (**b64/b64.hpp**) requires **STLSoft**; see [INSTALL.md](./INSTALL.md)
and [README.md](./README.md).


<!-- ########################### end of file ########################### -->
