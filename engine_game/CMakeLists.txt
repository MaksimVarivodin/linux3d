cmake_minimum_required(VERSION 3.15)
project(engine_game)

# Point to your vcpkg installation
set(CMAKE_TOOLCHAIN_FILE "C:/Users/Maksym/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(SDL3 REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
        SDL3::SDL3
        engine_lib
)
