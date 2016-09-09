# b64

**b64** is a very small and simple C-language library that provides
[Base-64](https://en.wikipedia.org/wiki/Base64) encoding and decoding. Also
provided is a header-only C++ wrapper.

The **b64** core library is a pure standalone component:

 - It has _zero dependencies_ on any other libraries. (Note: the C++ wrapper depends on the [STLSoft libraries](http://github.com/synesissoftware/STLSoft-1.9/);)
 - It has _zero dependencies_ on any part of the C standard library, except in debug builds (where it depends on `strchr()` and `assert()`);
 - It has _zero dependencies_ on any host operating system facilities;
 - It does not allocate any memory;
 - It is released under the [BSD license](https://en.wikipedia.org/wiki/BSD_licenses), which basically means its free for any use, but you can't claim it's yours.

Base-64 conversion of binary regions, using **b64**, is available as part of the distribution of [Pantheios](http://github.com/synesissoftware/pantheios/), a high-performance C++ diagnostic logging API library.
