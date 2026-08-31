# **b64** Changes <!-- omit in toc -->


## 1.5.8-beta1 - 6th August 2026



## 1.5.7 - 2nd August 2026

* Added modular GitHub Actions CI (**ci.yml** / **ci-cell.yml**) with install-smoke coverage;
* Converted **CHANGES.txt** to **CHANGES.md** and removed **HISTORY.md**;
* Expanded **FAQ.md**, **INSTALL.md**, and **README.md**;
* Removed legacy Visual Studio project/solution files and custom makefiles under **build/**;
* CMake improvements (incl. `BUILD_TESTING`, legacy MSVC warning suppression, absolute **STLSoft** include path, conditional **STLSoft** linkage for the C++ API);
* **CMake** package config: `find_dependency(STLSoft)` when the C++ API was built against the **STLSoft** package, so consumers of **`b64::core`** get a complete imported graph;
* Enhanced CMake helper scripts (shared **.sis/script_info_lines.txt**; **run_all_unit_tests.sh** `--unit-only` / `--component-only` and `--no-make` guard);
* Corrected `B64_VER_REVISION` to match the release revision;
* Project boilerplate updates (**.gitattributes**, **.gitignore**, **.vimrc**, **.vscode/settings.json**);


## 1.5.6 - 6th May 2025

* MinGW compatibility;
* Added '--no-shwild' flag (to **prepare_cmake.sh**);
* Various CMake scripts canonicalisation;


## 1.5.5 - 18th November 2024

* added CMake MSVC MT support;


## 1.5.4 - 17th October 2024

* Significant enhancement and refactoring around use of CMake;
* Compatibility with legacy versions of Visual C++;
* MinGW compatibility;
* General tidying;


## 1.5.3 - 24th September 2024

* fixed problem with `b64_decode()` buffer size check - thanks to Gerry Hornbill;
* added unit-tests to capture the problematic approximate return value from `b64_decode2()` when given null destination buffer pointer (for purpose of estimation of required buffer size);
* added **b64dec** example program;
* added **b64enc** example program;
* added missing STLSoft dependencies in unit-test CMake files;
* removed unncessary elements form CMake files;
* CMake files boilerplate changes;
* update to CMake build scripts;
* removing explicit inclusion of **b64/implicit_link.h** from unit test source files;
* code canonicalisation;
* improving C compatibility;


## 1.5.2 - 14th July 2024

* Compatible with xTests before and after 0.23;


## 1.5.1 - 14th July 2024

* Various CMake standardisations and simplifications;


## 1.4.8 - 10th July 2024

* Windows CMake compatibility;
* GCC compatibility;


## 1.4.7 - 6th February 2024

* CMake support;


## 1.4.6 - 12th October 2020

* added support for Visual C++ 15, 16;
* added support for GCC 8;
* removed default dependence on xContract (except in presence of B64_NO_USE_XCONTRACT), and now is opt-in (in presence of B64_USE_XCONTRACT) and removed dependency on and use of xContract in makefiles;
* refactored makefiles;


## 1.4.5 - 11th October 2019

* removed dependency on/mention of environment variable STLSOFT_1_10 from project files;
* adding Post-Build events to execute tests;
* fixing missing <RuntimeLibrary>MultiThreadedDebug</RuntimeLibrary> in VC++ 10+ project files;
* tidying solution files;


## 1.4.2 - 4th February 2012

* added `b64_getStatusCodeString()`, `b64_getStatusCodeStringLength()`; deprecated `b64_getErrorString()` and `b64_getErrorStringLength()`;
* now implemented shims in terms of `b64_getStatusCodeString()` and `b64_getStatusCodeStringLength()`;
* ensures exception bears code `B64_RC_TRUNCATED_INPUT` when input truncated (it previously was passing `B64_RC_OK`);
* abstracted declaration and application of string access shims, in readiness for widestring builds and/or STLSoft 1.10+;
* added implicit link support for VC++10;
* added core library names according to implicit link format, i.e. b64.1.core.*;
* added makefile for GCC 4.5;
* added makefile for GCC 4.6;
* added makefile for GCC 4.7;
* NOTE: bundles shwild 0.9.20;
* NOTE: bundles xContract 0.3.7;
* NOTE: bundles xTests 0.16.4;
* NOTE: depends on STLSoft 1.9.111;


## 1.4.1 - 20th January 2010

* added test variant for all makefile projects;
* added support for Borland 5.9+;
* preparations for widestring support;
* fixed defect in `b64_encode()`/`b64_encode2()`;
* fixed defective use of std::vector subscript operator;
* improvements in C++ API exception handling, including message and additional information;
* NOTE: bundles xContract 0.3.1;
* NOTE: bundles xTests 0.14.3;
* NOTE: depends on STLSoft 1.9.89;


## 1.3.4 - 24th August 2008

* fix for GCC 4.x's defective resolution of function template names for std::string overloads of string access shim;
* fixed printf format-specifier warning in example.2.c;


## 1.3.3 - 3rd August 2008

* fixed warning in GCC 4.x makefile;
* added makefiles for GCC 4.1, 4.2, 4.3;
* added makefiles for VC++ 9;
* fixed printf format-specifier warning in example.2.c;


## 1.3.2 - 13th May 2008

* Win64 compatibility;


## 1.3.1 - 15th March 2008

* added ability to customise namespace name;
* renamed test/example/sample directories and filenames to fit in with the prevailing standard in all Synesis-related libraries;


## 1.2.6 - 9th February 2008

* workaround for weird GCC bug on 64-bit Linux;


## 1.2.5 - 8th February 2008

* compatibility with Visual C++ 8+ "Safe String" library;


## 1.2.4 - 30th April 2007

* compatibility with STLSoft 1.9.1;
* version released on Extended STL, volume 1: CD;


## 1.2.3 - 26th January 2007

* trimming of unused/unwanted makefiles;
* fix of omission (in 1.2.2) of compiled HTML help (.CHM) file;
* minor changes to help;


## 1.2.2 - 22nd January 2007

* now roots the distribution under b64-X.Y, e.g. b64-1.2.2;
* minor fixes to makefiles;
* minor changes to help;


## 1.2.1 - 7th December 2006

* New error functions to API: `b64_getErrorString()` and `b64_getErrorStringLength()`;
* Change to C++ namespace and include file path: deprecated **b64/cpp/b64.hpp** in favour of **b64/b64.hpp**; all public C++ names moved from `b64::cpp` into `b64` (old namespace retained for backwards compatibility);
* fix to `b64::decode()` to avoid invoking subscript operator for empty `blob_t` instances;


## 1.1.3 - 2nd August 2006

* moved the Null Object dummy variables out of b64_encode_() and b64_decode_() into callers, and added precondition enforcements into b64_encode_() and b64_decode_();
* removed obsolete inclusions and definitions from b64/cpp/b64.hpp;
* now assumes contiguous string type for Dinkumware C++ libraries for VC++ up to version 7.1;
* added B64_NO_CONTIGUOUS_STRING_TYPE that, if defined, suppresses contiguous assumption;
* fixed a bug in encode(), whereby the coding_exception would have had the wrong return code;


## 1.1.2 - 26th July 2006

* Minor changes to the header file for the C++ mapping, to be compatible with latest STLSoft (1.9.1 beta 16 - download from http://stlsoft.org/downloads.html);
* Minor fixes/changes to makefiles;
* Minor fixes to the documentation;


## 1.1.1 - 28th April 2006

* Change tracking begins with this release (v1.1, 28th April 2006);


<!-- ########################### end of file ########################### -->
