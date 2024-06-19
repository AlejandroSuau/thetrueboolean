#include <gtest/gtest.h>

int sum(int a, int b) {
    return a + b;
}

TEST(SumTest, Test1) {
    int a = 1;
    int b = 4;
    int expected_value = 5;
    int sum_result = sum(a, b);

    EXPECT_EQ(sum_result, expected_value);
}

TEST(SumTest, Test2) {
    int a = 5;
    int b = 10;
    int expected_value = 15;
    int sum_result = sum(a, b);

    EXPECT_EQ(sum_result, expected_value);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}