if(BUILD_TESTING)
  set(ENV{GTEST_COLOR} 1)
  message(STATUS "GTest color is $ENV{GTEST_COLOR}")

  # Include the GTest package
  find_package(GTest)

  # Create the test binary, configure include paths and linked libraries
  add_executable(testsum sum_test.cpp)
  target_link_libraries(testsum PRIVATE math GTest::gtest_main)

  gtest_discover_tests(testsum)
endif()
