cmake_minimum_required(VERSION 3.5)

project(SimpleHanoiTowers)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE src_files
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE header_files
    ${PROJECT_SOURCE_DIR}/src/*.h
)

add_executable(${PROJECT_NAME} ${src_files} ${header_files})