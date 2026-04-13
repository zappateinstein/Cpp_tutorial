include(CTest)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(test_string_tools test_string_tools.cpp)
target_link_libraries(test_string_tools string_tools)
add_test(NAME TestStringTools COMMAND test_string_tools)
