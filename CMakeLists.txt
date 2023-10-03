cmake_minimum_required(VERSION 3.12)

project(
  testing
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS
    ON
    CACHE INTERNAL "")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# No need to use enable_testing() since we include ctest
include(CTest)

add_subdirectory(test)
add_subdirectory(src)

add_executable(main src/main.cpp)
target_include_directories(main PRIVATE include)

# Only link if we are in testing mode otherwise we do not need to creae this
# target and link to it
if(BUILD_TESTING)
  target_link_libraries(main PRIVATE math)
endif()
