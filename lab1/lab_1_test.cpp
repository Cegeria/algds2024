#include "lab_1.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(Min_Value_Of_Two, Different_Numbers)
{
    EXPECT_EQ(-2, min_2(2, -2));
    EXPECT_EQ(3, min_2(5, 3));
    EXPECT_EQ(-4, min_2(-4, -2));
}

TEST(Min_Value_Of_Two, Equal_Numbers)
{
    EXPECT_EQ(3, min_2(3, 3));
}

TEST(Min_Value_Of_Three, Different_Numbers)
{
    EXPECT_EQ(1, min_3(1, 2, 3));
    EXPECT_EQ(0, min_3(2, 1, 0));
    EXPECT_EQ(-1, min_3(-1, 0, 1));
}

TEST(Min_Value_Of_Three, Equal_Numbers)
{
    EXPECT_EQ(2, min_3(2, 5, 5));
    EXPECT_EQ(-1, min_3(-1, -1, 0));
    EXPECT_EQ(1, min_3(1, 1, 1));
}

TEST(Solve_Function, No_Board)
{
    int N = 0;
    int **A = InitMtx(N, N);
    EXPECT_EQ(0, Solve(A, N, N));
}

TEST(Solve_Function, One_On_One_Board)
{
    int N = 1;
    int **A = InitMtx(N, N);
    A[0][0] = 1;
    EXPECT_EQ(1, Solve(A, N, N));
    free(A);
}

TEST(Solve_Function, Empty_Board)
{
    int N = 5;
    int M = 7;
    int **A = InitMtx(N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = 0;
        }
    }
    EXPECT_EQ(0, Solve(A, N, M));
    free(A);
}

TEST(Solve_Function, Simple_Path)
{
    int N = 5;
    int M = 4;
    int **A = InitMtx(N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = 2;
        }
    }
    A[0][1] = 1;
    A[1][2] = 0;
    A[2][1] = 1;
    A[3][0] = 0;
    A[4][1] = 1;
    EXPECT_EQ(3, Solve(A, N, M));
    free(A);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
} 
