/*
  File: stack.h
  Details: Definition of stack class.
 */
#include "../node/node.h"

#pragma once
template<class StackData>
class Stack {
  friend std::ostream& operator<<(std::ostream& os, Stack StackInstance);
  public:
    Stack();
    Stack(StackData data);
    void Push(StackData data);
    StackData Pop();
    StackData Peek();
    bool isEmpty();
    int Length();
    Node<StackData>* TopNode();
  private:
    Node<StackData>* Top;
    int LENGTH;
};