# b64
**b64** is a very small and simple standalone C-language library that provides [Base-64](https://en.wikipedia.org/wiki/Base64) encoding and decoding.

## Table of Contents

1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Components](#components)
4. [Examples](#examples)
5. [Project Information](#project-information)

## Introduction

**b64** is a C-language library

**b64** is a very small and simple standalone C-language library that provides [Base-64](https://en.wikipedia.org/wiki/Base64) encoding and decoding. It also provides a header-only C++ wrapper.

The **b64** core library is a pure standalone component:

 - It has *zero dependencies* on any other libraries;
 - It has *zero dependencies* on any part of the C standard library, except in debug builds (where it depends on `strchr()` and `assert()`);
 - It has *zero dependencies* on any host operating system facilities;
 - It does not allocate any memory;
 - It is released under the [BSD license](https://en.wikipedia.org/wiki/BSD_licenses), which basically means its free for any use, but you can't claim it's yours.

Base-64 conversion of binary regions, using **b64**, is available as part of the distribution of [Pantheios](http://github.com/synesissoftware/pantheios/), a high-performance C++ diagnostic logging API library.


 (Note: the C++ wrapper depends on the [STLSoft libraries](http://github.com/synesissoftware/STLSoft-1.9/);)

## Installation

T.B.C.

## Components

### C API / core library

```C

enum B64_RC
{
        B64_RC_OK                   =   0   /* Operation was successful. */
    ,   B64_RC_INSUFFICIENT_BUFFER  =   1   /* The given translation buffer was not of sufficient size. */
    ,   B64_RC_TRUNCATED_INPUT      =   2   /* The input did not represent a fully formed stream of octet couplings. */
    ,   B64_RC_DATA_ERROR           =   3   /* Invalid data. */
};

enum B64_FLAGS
{
        B64_F_LINE_LEN_USE_PARAM    =   0x0000  /* Uses the lineLen parameter to b64_encode2(). Ignored by b64_decode2(). */
    ,   B64_F_LINE_LEN_INFINITE     =   0x0001  /* Ignores the lineLen parameter to b64_encode2(). Line length is infinite. Ignored by b64_decode2(). */
    ,   B64_F_LINE_LEN_64           =   0x0002  /* Ignores the lineLen parameter to b64_encode2(). Line length is 64. Ignored by b64_decode2(). */
    ,   B64_F_LINE_LEN_76           =   0x0003  /* Ignores the lineLen parameter to b64_encode2(). Line length is 76. Ignored by b64_decode2(). */
    ,   B64_F_LINE_LEN_MASK         =   0x000f  /* Mask for testing line length flags to b64_encode2(). Ignored by b64_encode2(). */
    ,   B64_F_STOP_ON_NOTHING       =   0x0000  /* Decoding ignores all invalid characters in the input data. Ignored by b64_encode2(). */
    ,   B64_F_STOP_ON_UNKNOWN_CHAR  =   0x0100  /* Causes decoding to break if any non-Base-64 [a-zA-Z0-9=+/], non-whitespace character is encountered. Ignored by b64_encode2(). */
    ,   B64_F_STOP_ON_UNEXPECTED_WS =   0x0200  /* Causes decoding to break if any unexpected whitespace is encountered. Ignored by b64_encode2(). */
    ,   B64_F_STOP_ON_BAD_CHAR      =   0x0300  /* Causes decoding to break if any non-Base-64 [a-zA-Z0-9=+/] character is encountered. Ignored by b64_encode2(). */
};


size_t
b64_encode(
    void const* src
,   size_t      srcSize
,   b64_char_t* dest
,   size_t      destLen
);

size_t
b64_decode(
    b64_char_t const*   src
,   size_t              srcLen
,   void*               dest
,   size_t              destSize
);

size_t
b64_encode2(
    void const* src
,   size_t      srcSize
,   b64_char_t* dest
,   size_t      destLen
,   unsigned    flags
,   int         lineLen    /* = 0 */
,   B64_RC*     rc         /* = NULL */
);

size_t
b64_decode2(
    b64_char_t const*   src
,   size_t              srcLen
,   void*               dest
,   size_t              destSize
,   unsigned            flags
,   b64_char_t const**  badChar    /* = NULL */
,   B64_RC*             rc         /* = NULL */
);

char const*
b64_getStatusCodeString(
    B64_RC  code
);

size_t
b64_getStatusCodeStringLength(
    B64_RC  code
);

```

### C++ API

```C++

typedef std::basic_string<b64_char_t>   string_t;
typedef std::vector<byte_t_>            blob_t;

class coding_exception;


string_t encode(void const* src, size_t srcSize, int flags, int lineLen = 0, B64_RC* rc = NULL);

string_t encode(void const* src, size_t srcSize);

template <typename T, size_t N>
string_t encode(T (&ar)[N]);

string_t encode(blob_t const &blob, int flags, int lineLen = 0, B64_RC* rc = NULL);

string_t encode(blob_t const &blob);


blob_t decode(b64_char_t const* src, size_t srcLen, int flags, b64_char_t const** badChar = NULL, B64_RC* rc = NULL);

blob_t decode(b64_char_t const* src, size_t srcLen);

template <class S>
blob_t decode(S const &str);

template <class S>
blob_t decode(int flags, S const &str);

blob_t decode(string_t const &str, int flags = B64_F_STOP_ON_BAD_CHAR);

blob_t decode(string_t const &str, int flags, b64_char_t const** badChar, B64_RC* rc = NULL);

```

## Examples

Examples are provided in the ```examples``` directory, along with a markdown description for each.

## Project Information

### Where to get help

[GitHub Page](https://github.com/synesissoftware/b64 "GitHub Page")

### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/b64.

### Dependencies

#### STLSoft (C++ API-only)

The C++ API depends on the STLSoft libraries, version 1.9.111 (or later). Version 1.10.1 beta15 (or later) is recommended.

* [STLSoft 1.9](http://github.com/synesissoftware/STLSoft-1.9/)
* [STLSoft 1.10](http://github.com/synesissoftware/STLSoft-1.10/) (Recommended)

#### xTests (unit-tests only)

The unit-test projects depend on the **xTests** project

* [xTests](http://github.com/synesissoftware/xTests/)


### Related projects

Projects in which **b64** is used include:

* [**Pantheios**](https://github.com/synesissoftware/Pantheios)

### License

**b64** is released under the 3-clause BSD license. See LICENSE for details.

