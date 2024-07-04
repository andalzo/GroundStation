# Find Qt6 packages
find_package(Qt6 REQUIRED COMPONENTS Widgets Multimedia MultimediaWidgets)

# Define the Qt6Interface target
add_library(Qt6Interface INTERFACE)

# Link Qt6 libraries
target_link_libraries(Qt6Interface INTERFACE Qt6::Widgets Qt6::Multimedia Qt6::MultimediaWidgets)

# Set properties to use Qt tools
set_target_properties(Qt6Interface PROPERTIES
        INTERFACE_AUTOMOC ON
        INTERFACE_AUTOUIC ON
        INTERFACE_AUTORCC ON
)

# Explicitly set paths to Qt tools
find_program(QT_MOC_EXECUTABLE NAMES moc HINTS "/usr/bin")
find_program(QT_RCC_EXECUTABLE NAMES rcc HINTS "/usr/bin")
find_program(QT_UIC_EXECUTABLE NAMES uic HINTS "/usr/bin")

if(NOT QT_MOC_EXECUTABLE)
    message(FATAL_ERROR "moc executable not found")
endif()

if(NOT QT_RCC_EXECUTABLE)
    message(FATAL_ERROR "rcc executable not found")
endif()

if(NOT QT_UIC_EXECUTABLE)
    message(FATAL_ERROR "uic executable not found")
endif()

set(CMAKE_AUTOMOC_MOC_OPTIONS ${QT_MOC_EXECUTABLE})
set(CMAKE_AUTORCC_RCC_OPTIONS ${QT_RCC_EXECUTABLE})
set(CMAKE_AUTOUIC_UIC_OPTIONS ${QT_UIC_EXECUTABLE})



