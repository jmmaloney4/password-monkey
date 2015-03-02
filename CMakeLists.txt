project(pm)
cmake_minimum_required(VERSION 2.8)

include_directories("${PROJECT_SOURCE_DIR}/include/")
add_library(pmcore include/pm.h src/pm.c include/aes.h src/aes.c)

