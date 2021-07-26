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
    SinglyLinkedList(Node<int> HeadNode);
    unsigned int Length();
    void AddToTail(Node<int> DataNode);
    Node<int>* GetHead();
    Node<int>* GetTail();
    Node<int> RemoveLastTail();

  private:
    unsigned int LENGTH;
    Node<int>* Head;

    Node<int>* GetSecondToLastNode();
};