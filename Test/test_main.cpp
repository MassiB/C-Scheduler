/**
 * @file test_main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <gtest/gtest.h>
#include <gmock/gmock.h>

template < typename T >
T sum(const T &elem) {
    return elem;
}

template < typename T, typename ...Arg >
T sum(const T &elem , const Arg&&... arg) {
    return elem + sum(arg...);
} 

TEST(TestSumFunction, Test_sum)
{
    EXPECT_EQ(2, sum <int>(2,0));
}
/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
};