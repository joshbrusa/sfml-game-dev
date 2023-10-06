cmake_minimum_required(VERSION 3.27)
project(conan-demo)
add_executable(${PROJECT_NAME} src/main.cpp)

find_package(SFML REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-graphics)