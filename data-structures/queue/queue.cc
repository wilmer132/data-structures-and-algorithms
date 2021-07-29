/*
  File: queue.cc
  Details: Implementation of queue class.
 */
#include "queue.h"
#include "../node/node.h"

template <class QueueData>
Queue<QueueData>::Queue() {
  LENGTH = 0;
  head = nullptr;
  tail = nullptr;
}

template <class QueueData>
Queue<QueueData>::Queue(QueueData data) {
  LENGTH = 1;
  head = new Node<QueueData>(data);
  tail = nullptr;
}

template <class QueueData>
void Queue<QueueData>::Add(QueueData data) {
  if (LENGTH == 0) {
    LENGTH++;
    head = new Node<QueueData>(data);
    tail = nullptr;
    return;
  } 
  Node<QueueData>* NewData = new Node<QueueData>(data);
  if (LENGTH == 1) {
    head->next = NewData;
    tail = NewData;
  } else {
    tail->next = NewData;
    tail = tail->next;
  }
  LENGTH++;
  return;
}

template <class QueueData>
QueueData Queue<QueueData>::Remove() {
  if (LENGTH == 0) {
    throw("Cannot remove element. Queue is empty.");
  } 
  QueueData data = head->value;
  if (LENGTH == 1) {
    delete head;
    head = nullptr;
  } else if (LENGTH == 2) {
    delete head;
    head = tail;
    tail = nullptr;
  } else {
    Node<QueueData>* nextHead = head->next;
    delete head;
    head = nextHead;
  }
  LENGTH--;
  return data;
}

template <class QueueData>
QueueData Queue<QueueData>::Peek() {
  if (LENGTH == 0) {
    throw("Cannot peek element. Queue is empty");
  }
  return head->value;
}

template <class QueueData>
bool Queue<QueueData>::isEmpty() {
  return (LENGTH == 0);
}

template <class QueueData>
Node<QueueData>* Queue<QueueData>::GetHeadNode() {
  return head;
}

template <class QueueData>
int Queue<QueueData>::Length() {
  return LENGTH;
}

std::ostream& operator<<(std::ostream& os, Queue<std::string> QueueInstance) {
  os << "{";
  Node<std::string>* CurrentNode = QueueInstance.GetHeadNode();
  int NodeCtr = 0;
  while (CurrentNode != nullptr) {
    os << *CurrentNode;
    if (NodeCtr != (QueueInstance.Length() - 1)) os << ", ";
    CurrentNode = CurrentNode->next;
    NodeCtr++;
  }
  os << "}";
  return os;
}

std::ostream& operator<<(std::ostream& os, Queue<int> QueueInstance) {
  os << "{";
  Node<int>* CurrentNode = QueueInstance.GetHeadNode();
  int NodeCtr = 0;
  while (CurrentNode != nullptr) {
    os << *CurrentNode;
    if (NodeCtr != (QueueInstance.Length() - 1)) os << ", ";
    CurrentNode = CurrentNode->next;
    NodeCtr++;
  }
  os << "}";
  return os;
}

template class Queue<int>;
template class Queue<std::string>;