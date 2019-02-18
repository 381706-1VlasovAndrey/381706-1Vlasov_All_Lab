#include "gtest.h"
#include "Stack.h"

TEST(Stack, can_create) {
  ASSERT_NO_THROW(TStack<int> A(9));
}

TEST(Stack, can_not_create_with_negative_size) {
  ASSERT_ANY_THROW(TStack<int> A(-9));
}

TEST(Stack, copy_empty_stack)
{
  TStack<int> A(9);
  ASSERT_NO_THROW(TStack<int> B(A));
}

TEST(Stack, can_put_and_get) {
  TStack<int> A(9);
  A.Put(9);
  ASSERT_EQ(9, A.Get());
  A.Put(3);
  A.Put(6);
  ASSERT_EQ(6, A.Get());
  ASSERT_EQ(3, A.Get());
}

TEST(Stack, copy_stack)
{
  TStack<int> A(2);
  A.Put(3);
  A.Put(6);
  ASSERT_NO_THROW(TStack<int> B(A));
}

TEST(Stack, can_get_size)
{
  TStack<int> A(3);
  EXPECT_EQ(3, A.GetSize());
}

TEST(Stack, check_stack_is_full_false)
{
  TStack <int> A(1);
  ASSERT_FALSE(A.IsFull());
}

TEST(Stack, check_stack_is_full_true)
{
  TStack <int> A(1);
  S.Put(7);
  ASSERT_TRUE(A.IsFull());
}

TEST(Stack, check_stack_is_empty_false)
{
  TStack <int> A(1);
  A.Put(7);
  ASSERT_FALSE(A.IsEmpty());
}

TEST(Stack, check_stack_is_empty_true)
{
  TStack <int> A(1);
  ASSERT_TRUE(A.IsEmpty());
}

TEST(Stack, can_not_put_in_full_stack)
{
  TStack<int> A(2);
  A.Put(3);
  A.Put(7);
  ASSERT_ANY_THROW(A.Put(9));
}

TEST(Stack, can_not_get_in_empty_stack)
{
  TStack<int> A(3);
  ASSERT_ANY_THROW(A.Get());
}

TEST(Stack, sravnenie_true)
{
  TStack <int> A(1), B(1);
  A.Put(777);
  B.Put(777);
  ASSERT_TRUE(A == B);
}

TEST(Stack, sravnenie_false)
{
  TStack <int> A(1), B(1);
  A.Put(4);
  B.Put(5);
  ASSERT_FALSE(A == B);
}

TEST(Stack, sravnenie_stacks_different_size_false)
{
  TStack <int> A(4), B(5);
  ASSERT_FALSE(A == B);
}

TEST(Stack, sravnenie_stacks_different_top_false)
{
  TStack <int> A(3), B(3);
  A.Put(4);
  B.Put(2), 
  A.Put(3);
  ASSERT_FALSE(A == B);
}

TEST(Stack, negative_sravnenie_false)
{
  TStack <int> A(1), B(1);
  A.Put(7);
  B.Put(7);
  ASSERT_FALSE(A != B);
}

TEST(Stack, negative_sravnenie_true)
{
  TStack <int> A(1), B(1);
  A.Put(9);
  B.Put(7);
  ASSERT_TRUE(A != B);
}

TEST(Stack, negative_sravnenie_stacks_different_size_true)
{
  TStack <int> A(3), B(7);
  ASSERT_TRUE(A != B);
}

TEST(Stack, negative_sravnenie_stacks_different_top_false)
{
  TStack <int> A(3), B(3);
  A.Put(1);
  B.Put(1), 
  B.Put(2);
  ASSERT_TRUE(A != B);
}

TEST(Stack, prisvaivanie_true)
{
  TStack <int> A(3), B(1);
  A.Put(1), A.Put(7), A.Put(23);
  B = A;
  ASSERT_TRUE(B == A);
}