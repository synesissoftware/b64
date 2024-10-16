# SIS:AUTO_GENERATED: Remove this line if you edit the file, otherwise it will be overwritten
define_automated_test_program(test.unit.cpp.1 test.unit.cpp.1.cpp)

Significant enhancement and refactoring around use of CMake:
~ Compatibility with legacy versions of Visual C++;
~ Significant refactoring of ./CMakeLists.txt;
+ added CMake variable `NO_B64_CPP_API` that allows eschewal of use of **b64** C++ API (which relies on **STLSoft**);
+ added **cmake/LanguageFullVersion.cmake** file, which defines CMake variable `X_CMAKE_CXX_FULLSTANDARD`;
+ added **cmake/TargetMacros.cmake** file, which defines CMake functions `define_automated_test_program()` and `define_example_program()`, and applied them throughout examples and test programs;
+ **./prepare_cmake.sh** CMake driver script now recognises option '--no-cpp', which activates `NO_B64_CPP_API` and, therefore, turns off b64 C++ API;
+ added **./run_all_examples.sh**;
+ added **./run_all_scratch_tests.sh**;


