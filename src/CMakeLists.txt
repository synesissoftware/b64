
# ######################################################################## #
# File:     /src/CMakeLists.txt
#
# Purpose:  CMake lists file for b64 core library
#
# Created:  ...
# Updated:  6th May 2025
#
# ######################################################################## #


if(_BUILD_AS_UNIX)

	add_definitions(-DUNIX)
	add_definitions(-Dunix)
endif(_BUILD_AS_UNIX)

if(_BUILD_AS_WIN32)

	if(CMAKE_SIZEOF_VOID_P EQUAL 8)

		message (STATUS "Compiling for 64-bit Windows")

		add_definitions(-DWIN64)
	else()

		message (STATUS "Compiling for 32-bit Windows")

		add_definitions(-DWIN32)
	endif()
endif(_BUILD_AS_WIN32)

if(MSVC)
	if(MSVC_VERSION LESS 1920)

		add_compile_options("/wd4822")
	endif()

	if(MSVC_VERSION GREATER_EQUAL 1914)

		add_compile_options("/Zc:__cplusplus")
	endif()
endif(MSVC)


set(CORE_SRCS
	b64.c
)

add_library(core
	${CORE_SRCS}
)


# specify the primary public headers for the library, which controls whether
# they'll be installed
#
# NOTE: it is not yet known (to me, at least) how to include additional
# header files from sub-directories, so this is done below in an additional
# `install()` step
set(CORE_PUBLIC_HEADERS
	"${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/${PROJECT_NAME_LOWER}.h"
)
if(NOT NO_B64_CPP_API)

	list(APPEND CORE_PUBLIC_HEADERS
		"${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/${PROJECT_NAME_LOWER}.hpp"
	)
endif()

set_target_properties(core PROPERTIES
	OUTPUT_NAME "b64"
	PUBLIC_HEADER "${CORE_PUBLIC_HEADERS}"
)

target_include_directories(core
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

target_link_libraries(core
	PUBLIC
)

target_compile_options(core
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4
		>
)


# ##########################################################
# install

install(TARGETS core
	EXPORT project-targets
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME_LOWER}
)


# ############################## end of file ############################# #

