#include "Matrix.h"
#include <gtest.h>

TEST(Matrix, can_create)
{
  ASSERT_NO_THROW(TMatrix<int> A(3));
}

TEST(Matrix, can_not_create_with_negative_size)
{
  ASSERT_ANY_THROW(TMatrix<int> A(-3));
}

TEST(Matrix, can_set_elem)
{
  TMatrix<int> A(3);
  A[0][0] = 1;
  A[1][0] = 2;
  A[1][1] = 3;
  A[2][0] = 5;
  A[2][1] = 8;
  A[2][2] = 13;
  ASSERT_EQ(A[0][0], 1);
  ASSERT_EQ(A[1][0], 2);
  ASSERT_EQ(A[1][1], 3);
  ASSERT_EQ(A[2][0], 5);
  ASSERT_EQ(A[2][1], 8);
  ASSERT_EQ(A[2][2], 13);
}

EST(Matrix, can_not_get_does_not_exist_elem)
{
  TMatrix<int> A(3);
  ASSERT_ANY_THROW(A[0][1] = 5);
}

TEST(Matrix, can_get_determinant)
{
  TMatrix<int> A(4);
  for (int i = 0; i < 4; i++)
	for (int j = 0; j <= i; j++)
	  A[i][j] = 1 + i + j;
  ASSERT_EQ(A.GetDet(), 105);
}

