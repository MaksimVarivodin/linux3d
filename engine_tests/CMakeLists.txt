
include(FetchContent)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(engine_lib_test engine_lib_test.cpp)

target_link_libraries(engine_lib_test
        PRIVATE
        GTest::GTest
        engine_lib
)

add_test(engine_lib_gtest engine_lib_test)