# b64 - TODO <!-- omit in toc -->


## Table of Contents <!-- omit in toc -->

- [Functional improvements](#functional-improvements)
- [Performance improvements](#performance-improvements)
- [Packaging improvements](#packaging-improvements)


## Functional improvements

* [ ] Simplified C++ API when STLSoft not available or suppressed;
* [ ] Improve Developer Experience for the absolute simplest use case: add a minimal copy-pasteable C snippet and C++ snippet to **README.md** **Developer Experience** (matching the first examples and **doc/mainpage.md**), and consider simpler entry points if the simplest case is longer than it needs to be;
* [ ] Remove the C API functions (`b64_encode()`, `b64_encode2()`, `b64_decode()`, `b64_decode2()`, `b64_getErrorString()`, `b64_getErrorStringLength()`) and types (`B64_RC`, `B64_FLAGS`) from the **b64** C++ namespace, leaving them in the global namespace only, in a future version (2.x);


## Performance improvements

* [ ] Benchmarks;
* [ ] Add performance tests (**test/performance/**, programs **test.performance.\<subject\>**) for encoding and decoding, via both the C API and the C++ API, across a range of block sizes and line-length settings;


## Packaging improvements

* [x] ~~~GitHub Actions~~~ - ✅;
* [ ] GitHub Actions for all prepare permutations;
* [ ] **prepare_cmake.sh** should not offer '--mingw' unless on Windows;
* [ ] **prepare_cmake.sh** should not offer '--msvc-mt' unless on Windows;
* [x] ~~~Canonicalise the names of the **examples** and **test** directories (e.g. `test.unit.c.1` → `test.unit.<subject>`, `example.c.1` → `example.<subject>`), including their CMake targets and any references in documentation and CI~~~ - ✅;
* [x] ~~~scratch version reporter (**test/scratch/versions**, target **test.scratch.versions**)~~~ - ✅;


<!-- ########################### end of file ########################### -->
