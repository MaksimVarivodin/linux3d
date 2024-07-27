cmake_minimum_required(VERSION 3.10)
project(engine_lib VERSION 1.0)

# adding subdirs recursively
function(include_directories_recursive target dir)
    file(GLOB_RECURSE subdirs RELATIVE ${dir} ${dir}/*)
    foreach (subdir ${subdirs})
        if (IS_DIRECTORY ${dir}/${subdir})
            target_include_directories(${target} PUBLIC ${dir}/${subdir})
        endif ()
    endforeach ()
endfunction()

find_package(SDL2 REQUIRED)

add_library(${PROJECT_NAME} STATIC
        engine_lib.cpp
)
include_directories_recursive(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR})

# Link SDL2 library
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)

# Include SDL2 directories
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})