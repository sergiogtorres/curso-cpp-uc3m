set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
cmake_minimum_required(VERSION 3.10)
project(CppExercises)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(main
    src/main.cpp
    src/array_fijo.cpp
    src/vector_fijo.cpp
    src/array_fijo_smart.cpp
)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*, -fuchsia-*")

include_directories(C:/libs/GSL/include)