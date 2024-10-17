# b64 - History


----


17th October 2024 - 1.5.4
-------------------------

 * Significant enhancement and refactoring around use of CMake;
 * Compatibility with legacy versions of Visual C++;
 * MinGW compatibility;
 * General tidying;


24th September 2024 - 1.5.3
---------------------------

 * fixed problem with `b64_decode()` buffer size check - thanks to Gerry Hornbill;
 * added unit-tests to capture the problematic approximate return value from `b64_decode2()` when given null destination buffer pointer (for purpose of estimation of required buffer size)
 * added missing STLSoft dependencies in unit-test CMake files
 * added **b64dec** example program
 * added **b64enc** example program
 * removed unncessary elements form CMake files
 * CMake files boilerplate changes
 * update to CMake build scripts
 * removing explicit inclusion of **b64/implicit_link.h** from unit test source files
 * code canonicalisation
 * improving C compatibility


14th July 2024 - 1.5.2
----------------------

 * Compatible with xTests before and after 0.23


14th July 2024 - 1.5.1
----------------------

 * Various CMake standardisations and simplifications


10th July 2024 - 1.4.8
----------------------

 * Windows CMake compatibility
 * GCC compatibility


6th February 2024 - 1.4.7
-------------------------

 * CMake support


12th October 2020 - 1.4.6
-------------------------

 * added support for Visual C++ 15, 16
 * added support for GCC 8
 * removed default dependence on xContract (except in presence of B64_NO_USE_XCONTRACT), and now is opt-in (in presence of B64_USE_XCONTRACT) and removed dependency on and use of xContract in makefiles
 * refactored makefiles


11th October 2019 - 1.4.5
-------------------------

* removed dependency on/mention of environment variable STLSOFT_1_10 from project files
* adding Post-Build events to execute tests
* fixing missing <RuntimeLibrary>MultiThreadedDebug</RuntimeLibrary> in VC++ 10+ project files
* tidying solution files


4th February 2012 - 1.4.2
-------------------------

 * added b64_getStatusCodeString(), b64_getStatusCodeStringLength(); deprecated b64_getErrorString() and b64_getErrorStringLength()
 * now implemented shims in terms of b64_getStatusCodeString() and b64_getStatusCodeStringLength()
 * ensures exception bears code B64_RC_TRUNCATED_INPUT when input truncated (it previously was passing B64_RC_OK)
 * abstracted declaration and application of string access shims, in readiness for widestring builds and/or STLSoft 1.10+
 * added implicit link support for VC++10
 * added core library names according to implicit link format, i.e. b64.1.core.*
 * added makefile for GCC 4.5
 * added makefile for GCC 4.6
 * added makefile for GCC 4.7
 * NOTE: bundles shwild 0.9.20
 * NOTE: bundles xContract 0.3.7
 * NOTE: bundles xTests 0.16.4
 * NOTE: depends on STLSoft 1.9.111


20th January 2010 - 1.4.1
-------------------------

 * added test variant for all makefile projects
 * added support for Borland 5.9+
 * preparations for widestring support
 * fixed defect in b64_encode()/b64_encode2()
 * fixed defective use of std::vector subscript operator
 * improvements in C++ API exception handling, including message and additional information
 * NOTE: bundles xContract 0.3.1
 * NOTE: bundles xTests 0.14.3
 * NOTE: depends on STLSoft 1.9.89


24th August 2008 - 1.3.4
------------------------

 * fix for GCC 4.x's defective resolution of function template names for
   std::string overloads of string access shim
 * fixed printf format-specifier warning in example.2.c


3rd August 2008 - 1.3.3
-----------------------

 * fixed warning in GCC 4.x makefile
 * added makefiles for GCC 4.1, 4.2, 4.3
 * added makefiles for VC++ 9
 * fixed printf format-specifier warning in example.2.c


13th May 2008 - 1.3.2
---------------------

 * Win64 compatibility


15th March 2008 - 1.3.1
-----------------------

 * added ability to customise namespace name
 * renamed test/example/sample directories and filenames to fit in with the
   prevailing standard in all Synesis-related libraries


9th February 2008 - 1.2.6
-------------------------

 * workaround for weird GCC bug on 64-bit Linux


8th February 2008 - 1.2.5
-------------------------

 * compatibility with Visual C++ 8+ "Safe String" library


30th April 2007 - 1.2.4
-----------------------

 * compatibility with STLSoft 1.9.1; Extended STL, volume 1: CD


26th January 2007 - 1.2.3
-------------------------

 * minor fixes to distribution and documentation


22nd January 2007 - 1.2.2
-------------------------

 * distribution now roots under b64-X.Y, e.g. b64-1.2.2


7th December 2006 - 1.2.1
-------------------------

 * New error functions to API
 * Change to C++ namespace and include file path


2nd August 2006 - 1.1.3
------------------------------

 * No changes to functionality from 1.1.2
  (see CHANGES.txt for details)


26th July 2006 - 1.1.2
------------------------------

 * No changes to functionality from 1.1.1
  (see CHANGES.txt for details)


28th April 2006 - 1.1.1
-------------------------------

 * This will be kept up to date from v1.1 (28th April 2006) onwards.


<!-- ########################### end of file ########################### -->

