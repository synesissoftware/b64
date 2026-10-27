# b64 - TODO <!-- omit in toc -->


## Table of Contents <!-- omit in toc -->

- [Functional improvements](#functional-improvements)
- [Performance improvements](#performance-improvements)
- [Packaging improvements](#packaging-improvements)


## Functional improvements

* [ ] Simplified C++ API when STLSoft not available or suppressed;
* [ ] Decide and implement behaviour for malformed or truncated Base-64 input in `b64_decode2()`: a final partial quad (e.g. `"AAA"`) is silently ignored with `B64_RC_OK` and `B64_RC_TRUNCATED_INPUT` is never returned; misplaced padding is accepted silently (`"A=B="` decodes 2 bytes, `"AA=A"` decodes 3, and `"AA==AAAA"` ignores everything after the first padded quad); consider reporting via `B64_RC_TRUNCATED_INPUT` / `B64_RC_DATA_ERROR`, possibly behind opt-in flags, and pin the chosen behaviour with unit tests;
* [x] ~~~Developer Experience for the absolute simplest use case: minimal C and C++ snippets in **README.md** **Developer Experience** and **doc/mainpage.md**~~~ - ✅;
* [ ] Consider simpler entry points (e.g. a C helper that encodes into a fixed buffer without the size/pointer pair, or a C++ overload taking a string) if the simplest use case proves longer than it needs to be;
* [ ] Remove the C API functions (`b64_encode()`, `b64_encode2()`, `b64_decode()`, `b64_decode2()`, `b64_getErrorString()`, `b64_getErrorStringLength()`) and types (`B64_RC`, `B64_FLAGS`) from the **b64** C++ namespace, leaving them in the global namespace only, in a future version (2.x);


## Performance improvements

* [ ] Benchmarks;
* [x] Add performance tests (**test/performance/**, programs **test.performance.\<subject\>**) for encoding and decoding, via both the C API and the C++ API, across a range of block sizes and line-length settings;


## Packaging improvements

* [x] ~~~GitHub Actions~~~ - ✅;
* [ ] GitHub Actions for all prepare permutations;
* [ ] **prepare_cmake.sh** should not offer '--mingw' unless on Windows;
* [ ] **prepare_cmake.sh** should not offer '--msvc-mt' unless on Windows;
* [x] ~~~canonicalise the names of the **examples** and **test** directories and their CMake targets~~~ - ✅;
* [x] ~~~scratch version reporter (**test/scratch/versions**, target **test.scratch.versions**)~~~ - ✅;


<!-- ########################### end of file ########################### -->
