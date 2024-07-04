set(TEST_Gui OFF)

set(SOURCES impl/MainWindow.cpp
            impl/ManagementWindow.cpp
            impl/ComWindow.cpp
)

set(HEADERS include/Gui/MainWindow.h
            include/Gui/ManagementWindow.h
            include/Gui/ComWindow.h)

qt6_wrap_cpp(MOC_SOURCES ${HEADERS})

add_library(Gui
        STATIC
        ${SOURCES}
        ${MOC_SOURCES}
)


target_include_directories(Gui PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(Gui PUBLIC TSML NL Qt6Interface)

if(TEST_Gui)
    add_subdirectory(test)
endif()