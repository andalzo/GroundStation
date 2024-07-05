# Find Qt6 packages
find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui Multimedia MultimediaWidgets)

# Define the Qt6Interface target
add_library(Qt6Interface INTERFACE)

# Link Qt6 libraries
target_link_libraries(Qt6Interface INTERFACE Qt6::Widgets Qt6::Core Qt6::Gui Qt6::Multimedia Qt6::MultimediaWidgets)

# Qt standard project setup
qt_standard_project_setup()




