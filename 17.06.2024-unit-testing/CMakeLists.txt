cmake_minimum_required(VERSION 3.14)

SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    unit_testing
    Castle.cpp
    Knight.cpp
    example.cpp
)

target_link_libraries(
    unit_testing
    GTest::gtest_main
    GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(unit_testing)


# ======= Sección nueva ======= 
# Añadida para el ejemplo comentado sobre SumTest
add_executable(
    sum_test
    SumTest.cpp
)

target_link_libraries(
    sum_test
    GTest::gtest_main
    GTest::gmock_main
)

gtest_discover_tests(sum_test)
# ====== ====== ====== ======