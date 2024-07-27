cmake_minimum_required(VERSION 3.10)

project(engine_game VERSION 1.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} engine_lib)

target_include_directories( ${PROJECT_NAME} PUBLIC
        ../engine_lib
        ../engine_lib/point
        ../engine_lib/direction
)