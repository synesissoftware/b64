# b64 - TODO <!-- omit in toc -->


## Table of Contents <!-- omit in toc -->

- [Functional improvements](#functional-improvements)
- [Performance improvements](#performance-improvements)
- [Packaging improvements](#packaging-improvements)


## Functional improvements

* [ ] Simplified C++ API when STLSoft not available or suppressed;
* [ ] Remove the C API functions (`b64_encode()`, `b64_encode2()`, `b64_decode()`, `b64_decode2()`, `b64_getErrorString()`, `b64_getErrorStringLength()`) and types (`B64_RC`, `B64_FLAGS`) from the **b64** C++ namespace, leaving them in the global namespace only, in a future version (2.x);


## Performance improvements

* [ ] Benchmarks;


## Packaging improvements

* [x] ~~~GitHub Actions~~~ - ✅;
* [ ] GitHub Actions for all prepare permutations;
* [ ] **prepare_cmake.sh** should not offer '--mingw' unless on Windows;
* [ ] **prepare_cmake.sh** should not offer '--msvc-mt' unless on Windows;
* [x] ~~~scratch version reporter (**test/scratch/versions**, target **test.scratch.versions**)~~~ - ✅;


<!-- ########################### end of file ########################### -->
