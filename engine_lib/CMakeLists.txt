cmake_minimum_required(VERSION 3.15)
project(engine_lib)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use vcpkg
set(CMAKE_TOOLCHAIN_FILE "C:/Users/Maksym/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Find SDL3
find_package(SDL3 REQUIRED)

# Collect source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "src/*.hpp" "src/*.inl")

# Library target
add_library(engine_lib STATIC ${SOURCES} ${HEADERS})

# Collect only directories recursively
function(collect_include_dirs BASE_DIR OUTPUT_VAR)
    file(GLOB_RECURSE _dirs RELATIVE ${BASE_DIR} LIST_DIRECTORIES true ${BASE_DIR}/*)

    set(_filtered_dirs "")
    foreach(dir ${_dirs})
        if (IS_DIRECTORY ${BASE_DIR}/${dir}) # Ensure it's a directory
            list(APPEND _filtered_dirs ${BASE_DIR}/${dir})
        endif()
    endforeach()

    set(${OUTPUT_VAR} ${_filtered_dirs} PARENT_SCOPE)
endfunction()

# Call function to get all include directories
collect_include_dirs(${CMAKE_CURRENT_SOURCE_DIR}/src ENGINE_INCLUDE_DIRS)

# Set include directories
target_include_directories(engine_lib PUBLIC ${ENGINE_INCLUDE_DIRS} ${SDL3_INCLUDE_DIRS})


# Link libraries
target_link_libraries(engine_lib PRIVATE
        SDL3::SDL3
)

