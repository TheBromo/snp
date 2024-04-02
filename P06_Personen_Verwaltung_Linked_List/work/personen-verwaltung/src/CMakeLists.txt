cmake_minimum_required(VERSION 3.28)
project(personen-verwaltung C)

set(CMAKE_C_STANDARD 17)

add_executable(personen-verwaltung main.c list.c list.h person.c person.h)
