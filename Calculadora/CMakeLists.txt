cmake_minimum_required(VERSION 3.10)
project(Calculadora C)

set(CMAKE_C_STANDARD 99)

add_executable(Calculadora main.c stack.h stack.c expression.h expression.c user.c user.h)
target_link_libraries(Calculadora m)