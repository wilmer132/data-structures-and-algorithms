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
  std::cout << "\nTesting Adding Duplicates:" << std::endl;
  for (int i = 0; i < 10; i++) {
    MyHashTable.Remove(100);
  }
  std::cout << "\nHashTable Instance now:\n" << MyHashTable << std::endl;
  std::cout << "\nTesting Removing:" << std::endl;
  for (int i = 0; i < 10; i++) {
    MyHashTable.Remove(100);
  }
  std::cout << "\nHashTable Instance now:\n" << MyHashTable << std::endl;
  return 1;
}