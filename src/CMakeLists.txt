if(BUILD_TESTING)
  add_library(math STATIC lib.cpp)
  target_include_directories(math PUBLIC ../include)
endif()
