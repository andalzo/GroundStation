enable_testing()

add_executable(
        GuiHandlerTest
        test_main.cpp
)
target_link_libraries(
        GuiHandlerTest
        PUBLIC
        GTest::gtest_main
        GuiHandler
)

add_test(GuiHandlerTestCMAKE GuiHandlerTest)