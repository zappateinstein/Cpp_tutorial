cmake_minimum_required(VERSION 3.14)
project(homework_4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch Catch2 v2
include(FetchContent)
FetchContent_Declare(
  Catch2
  URL https://github.com/catchorg/Catch2/releases/download/v2.13.9/catch.hpp
  DOWNLOAD_NO_EXTRACT ON
)
FetchContent_GetProperties(Catch2)
if(NOT catch2_POPULATED)
  FetchContent_Populate(Catch2)
  file(COPY ${catch2_SOURCE_DIR}/catch.hpp DESTINATION ${CMAKE_BINARY_DIR}/include/catch2)
endif()

# Create interface library for ipb_algorithm
add_library(ipb_algorithm INTERFACE)
target_include_directories(ipb_algorithm INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Include tests
enable_testing()
add_subdirectory(tests)
