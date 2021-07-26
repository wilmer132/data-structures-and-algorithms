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

void HashTable::Add(int data) {
  if (LENGTH <= 0) {
    throw("HashTable is size 0. Re-construct instance with nonzero size");
  }
  unsigned int index = int_hash(data) % LENGTH;
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
      return true;
    }
    currentNode = currentNode->next;
  }
}