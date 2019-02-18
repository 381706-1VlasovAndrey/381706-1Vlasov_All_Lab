#include "Queue.h"
#include <gtest.h>

TEST(Queue, can_create) {
  ASSERT_NO_THROW(TQueue<int> A(9));
}

TEST(Queue, can_not_create_with_negative_size)
{
  ASSERT_ANY_THROW(TQueue<int> A(-9));
}

TEST(Queue, copy_empty_queue)
{
  TQueue<int> A(9);
  ASSERT_NO_THROW(TQueue<int> B(A));
}

TEST(Queue, copy_queue)
{
  TQueue<int> A(2);
  A.Put(3);
  A.Put(6);
  ASSERT_NO_THROW(TQueue<int> B(A));
}

TEST(Queue, can_put_and_get)
{
  TQueue<int> A(9);
  A.Put(9);
  ASSERT_EQ(9, A.Get());
  A.Put(3);
  A.Put(6);
  ASSERT_EQ(3, A.Get());
  ASSERT_EQ(6, A.Get());
}

TEST(Queue, check_queue_is_full_false)
{
  TQueue <int> A(1);
  ASSERT_FALSE(A.IsFull());
}

TEST(Queue, check_queue_is_full_true)
{
  TQueue <int> A(1);
  S.Put(7);
  ASSERT_TRUE(A.IsFull());
}

TEST(Queue, check_queue_is_empty_false)
{
  TQueue <int> A(1);
  A.Put(7);
  ASSERT_FALSE(A.IsEmpty());
}

TEST(Queue, check_queue_is_empty_true)
{
  TQueue <int> A(1);
  ASSERT_TRUE(A.IsEmpty());
}

TEST(Queue, can_not_put_in_full_queue)
{
  TQueue<int> A(2);
  A.Put(3);
  A.Put(7);
  ASSERT_ANY_THROW(A.Put(9));
}

TEST(Queue, can_not_get_in_empty_queue)
{
  TQueue<int> A(3);
  ASSERT_ANY_THROW(A.Get());
}