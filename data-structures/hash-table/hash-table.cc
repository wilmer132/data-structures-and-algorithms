/*
  File: hash-table.cc
  Details: Implementation of hash-table class.
 */
#include "hash-table.h"

HashTable::HashTable() {
  LENGTH = 0;
}

HashTable::HashTable(unsigned int tableLength) {
  LENGTH = tableLength;
  TableArray.resize(tableLength);
}

int HashTable::Length() {
  return LENGTH;
}

SinglyLinkedList HashTable::Index(int index) {
  return TableArray[index];
}

void HashTable::Add(int data) {
  if (LENGTH <= 0) {
    throw("HashTable is size 0. Re-construct instance with nonzero size");
  }
  unsigned int index = int_hash(data) % LENGTH;
  Node<int>* CurrentNode = TableArray[index].GetHeadNode();
  Node<int> DataNode = Node<int>(data);
  while (CurrentNode != nullptr) {
    if (*CurrentNode == DataNode) {
      
    }
    CurrentNode = CurrentNode->next;
  }
  TableArray[index].AddToTail(data, int_hash(data));
}

bool HashTable::Remove(int data) {
  if (LENGTH <= 0) {
    throw("HashTable is size 0. Re-construct instance with nonzero size");
  }
  unsigned int index = int_hash(data) % LENGTH;
  Node<int>* currentNode = TableArray[index].GetHeadNode();
  while (currentNode != nullptr) {
    if (currentNode->nodeHash == int_hash(data)) {
      TableArray[index].RemoveNode(currentNode);
      return true;
    }
    currentNode = currentNode->next;
  }
  return false;
}

std::ostream& operator<<(std::ostream& os, HashTable HashTableInstance) {
  os << "[";
  for(int i = 0; i < HashTableInstance.Length(); i++) {
    SinglyLinkedList CurrentLinkedList = HashTableInstance.Index(i);
    os << "[";
    if (CurrentLinkedList.Length() != 0) {
      Node<int>* CurrentNode = CurrentLinkedList.GetHeadNode();
      int NodeCtr = 0;
      while (CurrentNode != nullptr) {
        os << *CurrentNode;
        if (NodeCtr != CurrentLinkedList.Length() - 1) os << ", ";
        CurrentNode = CurrentNode->next;
        NodeCtr++;
      }
    }
    os << "]";
    if (i != (HashTableInstance.Length() - 1)) os << ", ";
  }
  os << "]";
  return os;
}