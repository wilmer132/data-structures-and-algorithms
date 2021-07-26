/*
  File: hash-table.h
  Details: Definition of hash-table class.
 */
#include <vector>
#include "../singly-linked-list/singly-linked-list.h"

#pragma once
 class HashTable {
   public:
    HashTable();
    HashTable(unsigned int tableLength);
    void Add(int data);
    bool Remove(int data);

   private:
    unsigned int LENGTH;
    std::vector<SinglyLinkedList> TableArray;
    std::hash<int> int_hash;
 };