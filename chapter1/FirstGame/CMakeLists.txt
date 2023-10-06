cmake_minimum_required(VERSION 3.27)
project(compressor)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

find_package(SFML REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-graphics)
