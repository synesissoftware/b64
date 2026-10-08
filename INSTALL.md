# b64 - Installation and Use <!-- omit in toc -->

**b64** is a classic-form C/C++ library, insofar as it has implementation
files in its **src** directory and header files in its **include/b64**
directory. Thus, once "installed", one must simply include **b64/b64.h**
(C API) or **b64/b64.hpp** (C++ API), and compile-in or link-in the
implementation.

The **C API** has no non-standard dependencies. The **C++ API** depends on
**STLSoft**. Building the project's tests additionally requires **xTests**
(and optionally recognises **shwild**).


## Table of Contents <!-- omit in toc -->

- [CMake](#cmake)
- [Bundled](#bundled)


## CMake

The primary choice for installation is by use of **CMake**.

1. Obtain the latest distribution of **b64**, from
   https://github.com/synesissoftware/b64/, e.g.

   ```bash
   $ mkdir -p ~/open-source
   $ cd ~/open-source
   $ git clone https://github.com/synesissoftware/b64/
   ```

2. Prepare the CMake configuration, via the **prepare_cmake.sh** script.

   For a minimal **C API**-only install (no **STLSoft** / **xTests**
   required):

   ```bash
   $ cd ~/open-source/b64
   $ ./prepare_cmake.sh --no-cpp --disable-testing -v
   ```

   For a full build including the **C++ API**, examples, and tests, install
   **STLSoft** 1.11 (and **xTests** for tests) via their own **CMake**
   scripts first, then:

   ```bash
   $ cd ~/open-source/b64
   $ ./prepare_cmake.sh -v
   ```

   If **STLSoft** is available as a source tree rather than an installed
   **CMake** package, pass its root with `--stlsoft-root-dir` / `-s`.

   (**Hint**: execute `$ ./prepare_cmake.sh --help` for more information.)

3. Run a build of the generated **CMake**-derived build files via the
   **build_cmake.sh** script, as in:

   ```bash
   $ ./build_cmake.sh
   ```

   (**NOTE**: if you provide the flag `--run-make` (=== `-m`) in step 2 then
   you do not need this step.)

4. As a check (when testing was not disabled), execute the built unit-test
   programs via **run_all_unit_tests.sh**, as in:

   ```bash
   $ ./run_all_unit_tests.sh
   ```

5. Install the library on the host, via `cmake`, as in:

   ```bash
   $ sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release
   ```

6. Then to use the library, it is a simple matter as follows:

   1. Assuming a simplest possible program to verify the installation:

      ```c
      /* main.c */
      #include <b64/b64.h>

      #include <stdio.h>
      #include <stdlib.h>
      #include <string.h>

      int main(void)
      {
          unsigned char const bytes[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
          size_t const cch = b64_encode(bytes, sizeof(bytes), NULL, 0);
          char* const enc = (char*)malloc(cch);

          if (NULL == enc)
          {
              return EXIT_FAILURE;
          }

          b64_encode(bytes, sizeof(bytes), enc, cch);

          printf("encoded: %.*s\n", (int)cch, enc);

          free(enc);

          return EXIT_SUCCESS;
      }
      ```

   2. Compile your project against **b64**:

      Due to the installation step (step 5 above) there is no requirement
      for an explicit include directory for **b64**:

      ```bash
      $ cc -c main.c
      ```

   3. Link your project against **b64**:

      Due to the installation step (step 5 above) there is no requirement
      for an explicit library directory for **b64**:

      ```bash
      $ cc main.o -lb64
      ```

   4. Test your project:

      ```bash
      $ ./a.out
      encoded: AQIDBAUGBwgJCg==
      $
      ```

   Consumers that use **CMake** may instead depend on the installed package:

   ```cmake
   find_package(b64 REQUIRED)
   target_link_libraries(your_target PRIVATE b64::core)
   ```

   When the installed **b64** was built with the C++ API, **`find_package(b64)`**
   pulls in **STLSoft** via **`find_dependency`**. An explicit
   `find_package(STLSoft REQUIRED)` is still fine (and required if you
   include **b64/b64.hpp** while using a build of **b64** that did not
   record the **STLSoft** package dependency).


## Bundled

**b64** is small enough that it is commonly bundled into other projects
(for example **Pantheios**). In that case:

* add **b64**'s **include** directory to your project's include path;
* compile **src/b64.c** into your build (or link a previously built
  **libb64**); and
* `#include <b64/b64.h>` (or **b64/b64.hpp** if the **C++ API** and
  **STLSoft** are available).


<!-- ########################### end of file ########################### -->
