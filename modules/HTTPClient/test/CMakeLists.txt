enable_testing()

add_executable(
        HTTPClientTest
        test_main.cpp
)
target_link_libraries(
        HTTPClientTest
        PUBLIC
        GTest::gtest_main
        GuiHandler
)

add_test(HTTPClientTestCMAKE HTTPClientTest)