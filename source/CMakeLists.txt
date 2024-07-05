qt6_add_executable(GroundStation main.cpp)

target_link_libraries(GroundStation PUBLIC GSServer Gui HTTPHandler)
