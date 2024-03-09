find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

if(WIN32)
    set(QT6_PATH "")
    set(CMAKE_PREFIX_PATH QT6_PATH)
endif()

add_library(Qt6Interface INTERFACE)


# sudo apt install qt6-base-dev !!!
target_link_libraries(Qt6Interface INTERFACE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets)