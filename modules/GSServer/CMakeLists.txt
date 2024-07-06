set(TEST_GSServer OFF)

add_library(GSServer
        STATIC
        impl/GSServer.cpp
)

target_include_directories(GSServer PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(GSServer PUBLIC TSML NL)

if(TEST_GSServer)
    add_subdirectory(test)
endif()
