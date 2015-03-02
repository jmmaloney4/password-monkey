project(keychain)
cmake_minimum_required(VERSION 2.8)

include_directories("${PROJECT_SOURCE_DIR}/include/")
add_library(kccore include/keychain.h src/keychain.c include/aes.h src/aes.c)

