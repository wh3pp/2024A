cmake_minimum_required(VERSION 3.5)
project(primo)
add_executable(primo ej1.cpp)
target_compile_options(primo PRIVATE -ftemplate-depth=100000)
