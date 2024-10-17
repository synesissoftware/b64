
include_directories(${CMAKE_SOURCE_DIR}/include)

if(UNIX)

	add_definitions(-DUNIX)
	add_definitions(-Dunix)
endif(UNIX)

if(WIN32)

	if(CMAKE_SIZEOF_VOID_P EQUAL 8)

		message (STATUS "Compiling for 64-bit Windows")

		add_definitions(-DWIN64)
	else()

		message (STATUS "Compiling for 32-bit Windows")

		add_definitions(-DWIN32)
	endif()
endif(WIN32)

if((MSVC) AND (MSVC_VERSION GREATER_EQUAL 1914))

	add_compile_options("/Zc:__cplusplus")
endif()

add_subdirectory(c)

if(NOT NO_B64_CPP_API)

	add_subdirectory(cpp)
endif()


# ############################## end of file ############################# #

