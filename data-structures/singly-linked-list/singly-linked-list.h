/*
  File: linked-list.h
  Details: Definition of singly linked list class.
 */
#include <iostream>
#include "../node/node.h"

#pragma once
class SinglyLinkedList {
  /*Declare outside-of-class friend ostream for custom cout*/
  friend std::ostream& operator<<(std::ostream& os, SinglyLinkedList InstanceLinkedList);
  public:
    SinglyLinkedList();
    SinglyLinkedList(Node HeadNode);
    unsigned int Length();
    void AddToTail(Node DataNode);
    Node* GetHead();
    Node* GetTail();
    Node RemoveLastTail();
    
  private:
    unsigned int LENGTH;
    Node* Head;

    Node* GetSecondToLastNode();
};