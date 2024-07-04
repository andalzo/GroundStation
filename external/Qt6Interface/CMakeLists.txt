find_package(Qt6 COMPONENTS Core Gui Widgets Multimedia MultimediaWidgets REQUIRED)

if(WIN32)
    set(QT6_PATH "")
    set(CMAKE_PREFIX_PATH QT6_PATH)
endif()

add_library(Qt6Interface INTERFACE)


target_link_libraries(Qt6Interface INTERFACE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Multimedia
        Qt6::MultimediaWidgets)
