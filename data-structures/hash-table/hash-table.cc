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

void HashTable::Add(std::string data) {
  if (LENGTH <= 0) {
    throw("HashTable is size 0. Re-construct instance with nonzero size");
  }
  unsigned int index = string_hash(data) % LENGTH;
  
}