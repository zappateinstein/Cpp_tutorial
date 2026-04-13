add_library(string_tools string_tools.cpp)
add_executable(hw1_main main.cpp)
target_link_libraries(hw1_main string_tools)
