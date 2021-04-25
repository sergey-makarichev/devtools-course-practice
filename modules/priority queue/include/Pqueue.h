// Copyright 2021 Makarychev Sergey
#ifndef MODULES_PQUEUE_INCLUDE_PQUEUE_H_
#define MODULES_PQUEUE_INCLUDE_PQUEUE_H_

#include <vector>

struct PriorityQueueElem {
  int priority;
  float elem;
  PriorityQueueElem() : priority(1), elem(1) {
  };
  PriorityQueueElem(int priority, float elem) {
    if (priority < 0)
      throw "wrong priority";
    this->priority = priority;
    this->elem = elem;
  };

  bool operator > (const PriorityQueueElem& e) const {
    return priority > e.priority;
  }
  bool operator < (const PriorityQueueElem& e) const {
    return priority < e.priority;
  }
  bool operator == (const PriorityQueueElem& e) const {
    return priority == e.priority;
  }
};

class PQueue {
 private:
  int size;
  int count;
  PriorityQueueElem* elems;
 public:
  explicit PQueue(int size = 10);
  PQueue(const PQueue& q);
  ~PQueue();
  bool IsEmpty()const;
  bool IsFull()const;
  void Push(PriorityQueueElem q);
  PriorityQueueElem Pop();
  bool operator == (const PQueue& pq) const;
  bool operator != (const PQueue& pq) const;
};

#endif  // MODULES_PQUEUE_INCLUDE_PQUEUE_H_
