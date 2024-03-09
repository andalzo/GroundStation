set(TEST_GuiHandler OFF)

add_library(GuiHandler
        STATIC
        #Header Files
        include/GuiHandler/GuiHandler.h
        #Implementations
        impl/GuiHandler.cpp
)

target_include_directories(GuiHandler PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(GuiHandler PUBLIC TSML NL Qt6Interface)

if(TEST_GuiHandler)
    add_subdirectory(test)
endif()