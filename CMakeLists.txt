cmake_minimum_required(VERSION 3.27)
project(GSBackend)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TEST_GS OFF)

add_subdirectory(external/FGSCommon)
add_subdirectory(external/TSML)
add_subdirectory(external/NL)

add_subdirectory(modules)

add_library(GSBackend STATIC
        source/GSBackend.cpp
        source/GSBackend.h)

target_link_libraries(GSBackend PUBLIC GSServer HTTPClient)

if(TEST_GS)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )

    FetchContent_MakeAvailable(googletest)

    add_subdirectory(test)
endif()
