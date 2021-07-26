/*
  File: singly-linked-list-test.cc
  Details: Testing of singly-linked-list data structure
*/
#include <iostream>
#include <list>
#include "../node/node.h"
#include "singly-linked-list.h"

int main() {
  std::cout << "Testing construction of SinglyLinkedList:\n" << std::endl;
  SinglyLinkedList FirstSinglyLinkedList = SinglyLinkedList();
  SinglyLinkedList SecondSinglyLinkedList = SinglyLinkedList(100);
  std::cout << "First instance is size " << FirstSinglyLinkedList.Length() << ": " << FirstSinglyLinkedList << std::endl;
  std::cout << "Second instance is size " << SecondSinglyLinkedList.Length() << ": " << SecondSinglyLinkedList << std::endl;

  std::cout << "\nTesting SinglyLinkedList value addition:\n" << std::endl;
  FirstSinglyLinkedList.AddToTail(1000);
  SecondSinglyLinkedList.AddToTail(2000);
  int MessageList[] = {200, 300, 400, 500};
  for (int i = 0; i < 4; i++) {
    SecondSinglyLinkedList.AddToTail(MessageList[i]);
  }
  std::cout << "Updated first instance is size " << FirstSinglyLinkedList.Length() << ": " << FirstSinglyLinkedList << std::endl; 
  std::cout << "Updated instance is size " << SecondSinglyLinkedList.Length() << ": " << SecondSinglyLinkedList << std::endl;

  std::cout << "\nTesting SinglyLinkedList value removal:\n" << std::endl;
  while (FirstSinglyLinkedList.Length() >= 0) {
    try {
      std::cout << "First instance value: " << FirstSinglyLinkedList.RemoveLastTail() << ". Size is now " 
      << FirstSinglyLinkedList.Length() << std::endl;
    } catch(char const* errorMessage) {
      std::cout << errorMessage << std::endl;
      break;
    }
  }
  std::cout << std::endl;
  while (SecondSinglyLinkedList.Length() >= 0) {
    try {
      std::cout << "Second instance value: " << SecondSinglyLinkedList.RemoveLastTail() << ". Size is now " 
      << SecondSinglyLinkedList.Length() << std::endl;
    } catch(char const* errorMessage) {
      std::cout << errorMessage << std::endl;
      break;
    }
  }

  return 1;
}