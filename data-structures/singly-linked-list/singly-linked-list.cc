/*
  File: singly-linked-list.cc
  Details: Implementation of singly linked list class.
 */
#include "../node/node.h"
#include "singly-linked-list.h"

/*Private Methods*/

/*
  Retrieves second to last node of linked list instance object.
*/
Node<int>* SinglyLinkedList::GetSecondToLastNode() {
  Node<int>* CurrentNode = Head;
  while (CurrentNode->next->next != nullptr) {
    CurrentNode = CurrentNode->next;
  }
  Node<int>* SecondToLastNode = CurrentNode;
  return SecondToLastNode;
}

/*Public Methods*/

/*
  Default constructor will have zero length and nullptr head.
*/
SinglyLinkedList::SinglyLinkedList() {
  LENGTH = 0;
}


/*
  Constructor can take Node parameter to define head. Length starts at 1.
  Uses heap memory to allocate space for new data.
*/

SinglyLinkedList::SinglyLinkedList(Node<int> HeadNode) {
  LENGTH = 1;
  Head = new Node<int>(HeadNode.value);
}

/*
  Retrieves length value.
*/
unsigned int SinglyLinkedList::Length() {
  return LENGTH;
}

/*
  Retrieve head of instance object.
*/

Node<int>* SinglyLinkedList::GetHead() {
  return Head;
}

/*
  Retrieves last node of linked list instance object.
*/

Node<int>* SinglyLinkedList::GetTail() {
  if (LENGTH <= 0) {
    return nullptr;
  } else if (LENGTH == 1) {
    return Head;
  } else {
    Node<int>* TailNode = GetSecondToLastNode()->next;
    return TailNode;
  }
}

/*
  Iterates over instance object and adds new node to tail, defining new tail.
*/
void SinglyLinkedList::AddToTail(Node<int> DataNode) {
  if (Head == nullptr) {
    Head = new Node<int>(DataNode.value);
  } else {
    Node<int>* TailNode = GetTail();
    TailNode->next = new Node<int>(DataNode.value);
  }
  LENGTH++;
}

/*
  Iterates over instance object, retrieves and removes last tail, returning 
  heap memory.
*/
Node<int> SinglyLinkedList::RemoveLastTail() {
  if (LENGTH <= 0) {
    throw("Cannot remove Node from empty singly linked list.");
  } else if (LENGTH == 1) {
    LENGTH--;
    Node<int> TailCopy = *Head;
    delete Head;
    Head = nullptr;
    return TailCopy;
  } else {
    LENGTH--;
    Node<int>* SecondToLastNode = GetSecondToLastNode();
    Node<int>* LastNode = SecondToLastNode->next;
    Node<int> LastNodeCopy = *LastNode;
    delete LastNode;
    SecondToLastNode->next = nullptr;
    return LastNodeCopy;
  }
}

/*
  Define custom printing of instance data structure
*/
std::ostream& operator<<(std::ostream& os, SinglyLinkedList InstanceLinkedList) {
  Node<int>* CurrentNode = InstanceLinkedList.GetHead();
  unsigned int itr = 0;
  os << "{";
  while (CurrentNode != nullptr) {
    if (itr == (InstanceLinkedList.Length() - 1)) {
      os << *CurrentNode;
    } else {
      os << *CurrentNode << ", ";
    }
    CurrentNode = CurrentNode->next;
    itr++;
  }
  os << "}";
  return os;
}