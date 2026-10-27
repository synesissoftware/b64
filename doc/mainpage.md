# b64 {#mainpage}

**b64** is a very small and simple standalone C-language library that
provides [Base-64](https://en.wikipedia.org/wiki/Base64) encoding and
decoding, together with a header-only C++ wrapper.


## Modules

* @ref group__b64_api - the core C API (**b64/b64.h**): `b64_encode()`,
  `b64_encode2()`, `b64_decode()`, `b64_decode2()`, and the status-code
  description functions;
* @ref group__b64_cpp_api - the header-only C++ API (**b64/b64.hpp**);


## C API {#section__c_api}

The core library (**b64/b64.h**) is a pure standalone C component: it has no
dependencies, does not allocate memory, and is usable from C and C++. The
caller supplies all buffers.

* @ref b64::b64_encode "b64_encode()" / @ref b64::b64_encode2 "b64_encode2()"
  encode binary data to Base-64, the latter adding line-length control
  (`B64_F_LINE_LEN_*`) and a status code (@ref b64::B64_RC "B64_RC");
* @ref b64::b64_decode "b64_decode()" / @ref b64::b64_decode2 "b64_decode2()"
  decode Base-64 to binary data, the latter adding strictness flags
  (`B64_F_STOP_ON_*`), a pointer to the offending character, and a status
  code;
* b64_getStatusCodeString() / b64_getStatusCodeStringLength() describe a
  @ref b64::B64_RC "B64_RC";

The simplest use is with a fixed-size buffer:

```c
#include <b64/b64.h>

unsigned char const bytes[] = { 1, 2, 3 };
char                enc[8];
size_t const        n       =   b64_encode(bytes, sizeof(bytes), enc, sizeof(enc));  /* n == 4; enc is "AQID" */
```

For input of unknown size, every function follows the same two-call
pattern: pass a `NULL` destination to obtain the required buffer size,
allocate, then call again. The encoded form is **not** NUL-terminated.

```c
#include <b64/b64.h>

#include <stdlib.h>

unsigned char const bytes[] = { 0x01, 0x02, 0x03, 0x04 };

size_t const    n       =   b64_encode(bytes, sizeof(bytes), NULL, 0);
b64_char_t*     encoded =   (b64_char_t*)malloc(n);

if (NULL != encoded)
{
    size_t const m = b64_encode(bytes, sizeof(bytes), encoded, n);

    /* ... use encoded[0 .. m) ... */

    free(encoded);
}
```

Decoding is symmetrical, and @ref b64::b64_decode2 "b64_decode2()" reports malformed input through
its `flags`, `badChar`, and `rc` parameters. See @ref group__b64_api for the
full reference.


## C++ API {#section__cpp_api}

The header-only C++ API (**b64/b64.hpp**) provides `b64::encode()` and
`b64::decode()` wrappers over the C API. It requires
[STLSoft](https://github.com/synesissoftware/STLSoft) 1.11 or later.

```cpp
#include <b64/b64.hpp>

unsigned char const bytes[]     =   { 1, 2, 3 };
b64::string_t const encoded     =   b64::encode(bytes);    // "AQID"
b64::blob_t const   decoded     =   b64::decode(encoded);  // { 1, 2, 3 }
```


## Further reading

* The project [README](https://github.com/synesissoftware/b64#readme);
* The **examples** directory, each with a markdown description;
