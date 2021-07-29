/*
  File: queue.h
  Details: Definition of queue class.
 */
#include "../node/node.h"

#pragma once
template <class QueueData>
class Queue {
  friend std::ostream& operator<<(std::ostream& os, Queue<QueueData> QueueInstance);
  public:
    Queue();
    Queue(QueueData data);
    void Add(QueueData data);
    QueueData Remove();
    QueueData Peek();
    bool isEmpty();
    Node<QueueData>* GetHeadNode();
    int Length();
  private:
    Node<QueueData>* head;
    Node<QueueData>* tail;
    int LENGTH;
};