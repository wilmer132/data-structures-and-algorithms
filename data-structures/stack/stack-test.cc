/*
  File: stack-test.cc
  Details: Testing stack class.
 */
#include <iostream>
#include "stack.h"

int main() {
  try {
    Stack<int> StackOne = Stack<int>();
    std::cout << "StackOne: " << StackOne << std::endl;

    std::cout << "\nTesting pushing data:" << std::endl;
    for (int i = 0; i < 10; i++) {
      StackOne.Push(i);
    }
    std::cout << "StackOne: " << StackOne << std::endl;
    std::cout << "\nTesting popping data:" << std::endl;
    for (int i = 0; i < 10; i++) {
      StackOne.Pop();
      std::cout << "After popping: " << StackOne << std::endl;
    }
    std::cout << "StackOne: " << StackOne << std::endl;
  } catch(const char* errorMessage) {
    std::cout << errorMessage << std::endl;
  }

  return 1;
}