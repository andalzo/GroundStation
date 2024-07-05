set(TEST_HTTPClient OFF)

qt6_add_library(HTTPClient
        STATIC
        impl/HTTPClient.cpp
)

target_include_directories(HTTPClient PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(HTTPClient PUBLIC TSML NL)

if(TEST_HTTPClient)
    add_subdirectory(test)
endif()
