add_library(b64.core b64.c)
target_link_libraries(b64.core)
if(NOT "${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    find_package(xContract QUIET)
    if(xContract_FOUND)
        target_compile_definitions(b64.core PRIVATE SYNESIS_VARIANT_TEST)
        target_link_libraries(b64.core PRIVATE xContract::xContract)
    else()
        target_compile_definitions(b64.core PRIVATE B64_NO_USE_XCONTRACT)
        message(AUTHOR_WARNING "The xContract framework not found. Cannot use contracts.")
    endif()
endif()
set_target_properties(b64.core PROPERTIES
    OUTPUT_NAME "b64"
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER
        "${CMAKE_SOURCE_DIR}/include/b64/b64.hpp;${CMAKE_SOURCE_DIR}/include/b64/b64.h")
target_include_directories(b64.core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

install(TARGETS b64.core
    EXPORT project-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/b64
)

