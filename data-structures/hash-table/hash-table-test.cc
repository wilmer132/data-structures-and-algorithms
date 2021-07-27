/*
  File: hash-table-test.cc
  Details: Test hash-table class implementation
*/
#include <iostream>
#include "hash-table.h"

int main() {
  HashTable MyHashTable = HashTable(4);
  std::cout << "First HashTable:\n" << MyHashTable << std::endl;
  std::cout << "\nTesting Adding:" << std::endl;
  for (int i = 0; i < 10; i++) {
    MyHashTable.Add(i);
  }
  std::cout << "\nHashTable Instance now:\n" << MyHashTable << std::endl;
  std::cout << "\nTesting Removing:" << std::endl;
  for (int i = 0; i < 10; i++) {
    MyHashTable.Remove(i);
  }
  std::cout << "\nHashTable Instance now:\n" << MyHashTable << std::endl;
  try {
    std::cout << "\nTesting Adding Duplicates:" << std::endl;
    MyHashTable.Add(100);
    std::cout << "\nHashTable Instance now:\n" << MyHashTable << std::endl;
    std::cout << "\nTesting Removing:" << std::endl;
    MyHashTable.Remove(100);
    std::cout << "\nHashTable Instance now:\n" << MyHashTable << std::endl;
  } catch(const char* errorMessage) {
    std::cout << errorMessage << std::endl;
  }
  return 1;
}