# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (optimizer)

# add googletest subdirectory
add_subdirectory(googletest)

# this is so we can #include <gtest/gtest.h> 
include_directories(googletest/include)

# add header files in the lib
include_directories(lib) 

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cpp
    src/product.cpp
)

# Add an executable with the above sources
add_executable(run_opt ${SOURCES})


# Set the directories that should be included in the build command for this target

target_include_directories(run_opt
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/lib
)


enable_testing()
add_executable(run_opt_test
  src/product.cpp tests/utest-product.cpp
)

target_link_libraries(run_opt_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(run_opt_test )
