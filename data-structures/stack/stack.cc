/*
  File: stack.cc
  Details: Implementation of stack class.
 */
#include "stack.h"
#include "../node/node.h"

template<class StackData>
Stack<StackData>::Stack() {
  LENGTH = 0;
}

template<class StackData>
Stack<StackData>::Stack(StackData data) {
  LENGTH = 1;
  Top = new Node<StackData>(data);
}

template<class StackData>
void Stack<StackData>::Push(StackData data) {
  Node<StackData>* NewNode = new Node<StackData>(data);
  if (LENGTH <= 0) {
    LENGTH++;
    Top = NewNode;
    return;
  }
  NewNode->next = Top;
  Top = NewNode;
  LENGTH++;
}

template<class StackData>
StackData Stack<StackData>::Pop() {
  if (LENGTH <= 0) {
    throw("Cannot pop stack with zero items.");
  }
  LENGTH--;
  Node<StackData>* PoppedNode = Top;
  Node<StackData> PoppedNodeCopy = *PoppedNode;
  Top = Top->next;
  delete PoppedNode;
  return PoppedNodeCopy.value;
}

template<class StackData>
StackData Stack<StackData>::Peek() {
  if (LENGTH <= 0) {
    throw("Cannot peek stack with zero items.");
  }
  return Top->value;
}

template<class StackData>
bool Stack<StackData>::isEmpty() {
  return LENGTH == 0;
}

template<class StackData>
int Stack<StackData>::Length() {
  return LENGTH;
}

template<class StackData>
Node<StackData>* Stack<StackData>::TopNode() {
  return Top;
}

std::ostream& operator<<(std::ostream& os, Stack<int> StackInstance) {
  if (StackInstance.Length() <= 0) {
    os << "{Empty}";
    return os;
  }
  os << "{Top: ";
  Node<int>* CurrentNode = StackInstance.TopNode();
  int NodeCtr = 0;
  while (CurrentNode != nullptr) {
    os << *CurrentNode;
    if (NodeCtr != (StackInstance.Length() - 1)) os << " -> ";
    CurrentNode = CurrentNode->next;
    NodeCtr++;
  }
  os << "}";
  return os;
}

std::ostream& operator<<(std::ostream& os, Stack<std::string> StackInstance) {
  if (StackInstance.Length() <= 0) {
    os << "{Empty}";
    return os;
  }
  os << "{Top: ";
  Node<std::string>* CurrentNode = StackInstance.TopNode();
  int NodeCtr = 0;
  while (CurrentNode != nullptr) {
    os << *CurrentNode;
    if (NodeCtr != (StackInstance.Length() - 1)) os << " -> ";
    CurrentNode = CurrentNode->next;
    NodeCtr++;
  }
  os << "}";
  return os;
}

template class Stack<int>;
template class Stack<std::string>;