add_executable(test.unit.c.1 test.unit.c.1.c)
target_link_libraries(test.unit.c.1 b64.core xTests::xTests)
add_test(NAME test.unit.c.1 COMMAND ./test.unit.c.1)

