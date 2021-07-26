/*
  File: linked-list.h
  Details: Definition of singly linked list class. Class only for int
 */
#include <iostream>
#include "../node/node.h"

#pragma once
class SinglyLinkedList {
  /*Declare outside-of-class friend ostream for custom cout*/
  friend std::ostream& operator<<(std::ostream& os, SinglyLinkedList InstanceLinkedList);
  public:
    SinglyLinkedList();
    SinglyLinkedList(int value);
    unsigned int Length();
    void AddToTail(int data);
    int GetHead();
    int GetTail();
    int RemoveLastTail();

  private:
    unsigned int LENGTH;
    Node<int>* Head;

    Node<int>* GetSecondToLastNode();
    Node<int>* GetHeadNode();
    Node<int>* GetTailNode();
};