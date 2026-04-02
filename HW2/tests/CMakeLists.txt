include(CTest)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(test_image test_image.cpp)
target_link_libraries(test_image igg_image)
target_compile_definitions(test_image PRIVATE
  CMAKE_SOURCE_DIR="${PROJECT_SOURCE_DIR}")
add_test(NAME TestImage COMMAND test_image)
