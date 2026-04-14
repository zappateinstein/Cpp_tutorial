set(TEST_BINARY ${PROJECT_NAME}_test)
add_executable(${TEST_BINARY}
               test_named_vector.cpp
               test_ipb_algorithm.cpp
               test_main.cpp)

target_link_libraries(${TEST_BINARY} ipb_algorithm)
target_include_directories(${TEST_BINARY} PRIVATE
                          ${CMAKE_CURRENT_SOURCE_DIR}/../include
                          ${CMAKE_BINARY_DIR}/include)

enable_testing()
add_test(NAME ${TEST_BINARY} COMMAND ${TEST_BINARY})
