enable_testing()

add_executable(
        GSServerTest
        test_main.cpp
)
target_link_libraries(
        GSServerTest
        PUBLIC
        GTest::gtest_main
        GSServer
)

add_test(GSServerTestCMAKE GSServerTest)