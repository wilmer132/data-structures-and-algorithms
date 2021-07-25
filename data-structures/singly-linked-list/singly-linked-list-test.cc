/*
  File: singly-linked-list-test.cc
  Details: Testing of singly-linked-list data structure
*/
#include <iostream>
#include <list>
#include "../node/node.h"
#include "singly-linked-list.h"
using namespace std;

int main() {
  cout << "Testing construction of SinglyLinkedList:\n" << endl;
  SinglyLinkedList FirstSinglyLinkedList = SinglyLinkedList();
  Node Message = Node("Woohoo");
  SinglyLinkedList SecondSinglyLinkedList = SinglyLinkedList(Message);
  cout << "First instance is size " << FirstSinglyLinkedList.Length() << ": " << FirstSinglyLinkedList << endl;
  cout << "Second instance is size " << SecondSinglyLinkedList.Length() << ": " << SecondSinglyLinkedList << endl;

  cout << "\nTesting SinglyLinkedList value addition:\n" << endl;
  FirstSinglyLinkedList.AddToTail(Node("Hola"));
  SecondSinglyLinkedList.AddToTail(Node("Hola"));
  Node MessageList[] = {Node("Great"), Node("Awesome"), Node("Amazing"), Node("Incredible")};
  for (int i = 0; i < 4; i++) {
    Node SingleMessage = MessageList[i];
    SecondSinglyLinkedList.AddToTail(SingleMessage);
  }
  cout << "Updated first instance is size " << FirstSinglyLinkedList.Length() << ": " << FirstSinglyLinkedList << endl; 
  cout << "Updated instance is size " << SecondSinglyLinkedList.Length() << ": " << SecondSinglyLinkedList << endl;

  cout << "\nTesting SinglyLinkedList value removal:\n" << endl;
  while (FirstSinglyLinkedList.Length() >= 0) {
    try {
      cout << "First instance value: " << FirstSinglyLinkedList.RemoveLastTail() << ". Size is now " 
      << FirstSinglyLinkedList.Length() << endl;
    } catch(char const* errorMessage) {
      cout << errorMessage << endl;
      break;
    }
  }
  cout << endl;
  while (SecondSinglyLinkedList.Length() >= 0) {
    try {
      cout << "Second instance value: " << SecondSinglyLinkedList.RemoveLastTail() << ". Size is now " 
      << SecondSinglyLinkedList.Length() << endl;
    } catch(char const* errorMessage) {
      cout << errorMessage << endl;
      break;
    }
  }

  return 1;
}