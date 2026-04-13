cmake_minimum_required(VERSION 3.1)
project(homework_4)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# Header-only library target
add_library(ipb_algorithm INTERFACE)
target_include_directories(ipb_algorithm INTERFACE ${PROJECT_SOURCE_DIR}/include)

enable_testing()
add_subdirectory(tests)
