set(TEST_Gui OFF)

qt6_add_library(Gui
        STATIC
        impl/MainWindow.cpp 
        impl/ManagementWindow.cpp
        impl/ComWindow.cpp
)


target_include_directories(Gui PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(Gui PUBLIC TSML NL Qt6Interface)

if(TEST_Gui)
    add_subdirectory(test)
endif()
