project(pm)
cmake_minimum_required(VERSION 2.8)

add_subdirectory(gtest)
include_directories("${PROJECT_SOURCE_DIR}/gtest/include/")

include_directories("${PROJECT_SOURCE_DIR}/include/")
add_library(pmcore include/pmcore/pm.h src/pmcore/pm.c include/pmcore/aes.h src/pmcore/aes.c)

add_executable(pmtests src/pmtests/pmtests.c)
target_link_libraries(pmtests pmcore gtest gtest_main)
