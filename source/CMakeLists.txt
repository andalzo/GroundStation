add_executable(GroundStation main.cpp)

target_link_libraries(GroundStation PRIVATE
                 GSServer GuiHandler)