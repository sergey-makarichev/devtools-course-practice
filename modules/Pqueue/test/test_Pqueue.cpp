// Copyright 2021 Makarychev Sergey
#include <gtest/gtest.h>

#include "include/Pqueue.h"

TEST(Makarichev_Pqueue, Test_PriorityQueueElem_Wrong_Priority) {
  ASSERT_ANY_THROW(PriorityQueueElem(-1, 2));
}

TEST(Makarichev_Pqueue, Test_Create_PriorityQueueElem1) {
  PriorityQueueElem el = PriorityQueueElem();
  ASSERT_NO_THROW(el);
}

TEST(Makarichev_Pqueue, Test_Create_PriorityQueueElem2) {
  PriorityQueueElem el = PriorityQueueElem();
  ASSERT_EQ(1, el.priority);
}

TEST(Makarichev_Pqueue, Test_Create_PriorityQueueElem3) {
  PriorityQueueElem el = PriorityQueueElem();
  ASSERT_EQ(1.0f, el.elem);
}

TEST(Makarichev_Pqueue, Test_PriorityQueueElem_Correct_Priority) {
  ASSERT_NO_THROW(PriorityQueueElem(2, 4.8));
}

TEST(Makarichev_Pqueue, Test_PriorityQueueElem_Operator_More) {
  PriorityQueueElem e1 = { 18, 2.67 };
  PriorityQueueElem e2 = { 3, 78.9 };
  ASSERT_TRUE(e1 > e2);
}

TEST(Makarichev_Pqueue, Test_PriorityQueueElem_Operator_Less_1) {
  PriorityQueueElem e1 = { 3, 445 };
  PriorityQueueElem e2 = { 4, 980 };
  ASSERT_TRUE(e1 < e2);
}

TEST(Makarichev_Pqueue, Test_PriorityQueueElem_Operator_Less_2) {
  PriorityQueueElem e1 = { 9, 445 };
  PriorityQueueElem e2 = { 4, 580.9 };
  ASSERT_TRUE(e2 < e1);
}

TEST(Makarichev_Pqueue, Test_PriorityQueueElem_Operator_Less_3) {
  PriorityQueueElem e1 = { 12, 445 };
  PriorityQueueElem e2 = { 42, 580.9 };
  ASSERT_FALSE(e2 < e1);
}

TEST(Makarichev_Pqueue, Test_PriorityQueueElem_Operator_Equal1) {
  PriorityQueueElem e1 = { 9, 231.5 };
  PriorityQueueElem e2 = { 9, 12.4 };
  ASSERT_TRUE(e1 == e2);
}

TEST(Makarichev_Pqueue, Test_PriorityQueueElem_Operator_Equal2) {
  PriorityQueueElem e1 = { 10, 231.5 };
  PriorityQueueElem e2 = { 12, 231.5 };
  ASSERT_FALSE(e1 == e2);
}

TEST(Makarichev_Pqueue, Test_PriorityQueue_Wrong_Size) {
  ASSERT_ANY_THROW(PQueue(-1));
}

TEST(Makarichev_Pqueue, Test_PriorityQueue_Correct_Size) {
  ASSERT_NO_THROW(PQueue(12));
}

TEST(Makarichev_Pqueue, Test_PriorityQueue_Default_Constructor) {
    ASSERT_NO_THROW(PQueue());
}

TEST(Makarichev_Pqueue, Test_PriorityQueue_Copy_Constructor) {
  PriorityQueueElem el1 = { 1, 2 }, el2 = { 3, 6 }, el3 = { 4, 8 };
  PQueue q1(3);
  q1.Push(el1);
  q1.Push(el2);
  q1.Push(el3);
  PQueue q2(q1);
  ASSERT_EQ(q1, q2);
}

TEST(Makarichev_Pqueue, Test_PriorityQueue_Copy_Constructor_Empty) {
  PQueue q1(3);
  ASSERT_NO_THROW(PQueue q2(q1));
}

TEST(Makarichev_Pqueue, Test_PriorityQueue_IsEmpty) {
  PQueue q1(2);
  ASSERT_TRUE(q1.IsEmpty());
}

TEST(Makarichev_Pqueue, Test_PriorityQueue_IsFull) {
  PQueue q1(1);
  PriorityQueueElem el1 = { 1, 2 };
  q1.Push(el1);
  ASSERT_TRUE(q1.IsFull());
}

TEST(Makarichev_Pqueue, Test_PriorityQueue_Push_In_Empty_PQueue) {
  PQueue q1(2);
  PriorityQueueElem el1 = { 1, 2 };
  q1.Push(el1);
  ASSERT_NO_THROW(q1.Push(el1));
}

TEST(Makarichev_Pqueue, Test_PriorityQueue_Push_In_Full_PQueue) {
  PQueue q1(2);
  PriorityQueueElem el1 = { 1, 2 }, el2 = { 3, 6 }, el3 = { 4, 8 };
  q1.Push(el1);
  q1.Push(el2);
  ASSERT_ANY_THROW(q1.Push(el3));
}

TEST(Makarichev_Pqueue, Test_PriorityQueue_Correct_Push) {
  PriorityQueueElem el1[5] = { {9, 1}, {10, 1}, {1, 1}, {3, 1}, {2, 1} };
  PQueue q1(5);
  for (size_t i = 0; i < 5; i++)
    q1.Push(el1[i]);
  PriorityQueueElem el2[5] = { {1, 1}, {2, 1}, {3, 1}, {9, 1}, {10, 1} };
  PQueue q2(5);
  for (size_t i = 0; i < 5; i++)
    q2.Push(el2[i]);
  ASSERT_TRUE(q1 == q2);
}

TEST(Makarichev_Pqueue, Test_PriorityQueue_Pop_In_Empty_PQueue) {
  PQueue q1(2);
  ASSERT_ANY_THROW(q1.Pop());
}

TEST(Makarichev_Pqueue, Test_PriorityQueue_Correct_Pop) {
  PriorityQueueElem el1 = { 2, 3 };
  PQueue q1(1);
  q1.Push(el1);
  ASSERT_EQ(el1, q1.Pop());
}

TEST(Makarichev_Pqueue, Test_PriorityQueue_Unequall) {
  PriorityQueueElem el1 = { 2, 3 };
  PQueue q1(1), q2(1);
  q1.Push(el1);
  ASSERT_TRUE(q1 != q2);
}

TEST(Makarichev_Pqueue, Test_PriorityQueue_Equal) {
  PQueue q1(3), q2(1);
  ASSERT_FALSE(q1 == q2);
}
