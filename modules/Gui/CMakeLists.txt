set(TEST_Gui OFF)

add_library(Gui
        STATIC
        #Header Files
        include/Gui/MainWindow.h
        include/Gui/ManagementWindow.h
        include/Gui/ComWindow.h
        #Implementations
        impl/MainWindow.cpp
        impl/ManagementWindow.cpp
        impl/ComWindow.cpp
)

target_include_directories(Gui PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(Gui PUBLIC TSML NL Qt6Interface)

if(TEST_Gui)
    add_subdirectory(test)
endif()