/*
  File: hash-table.h
  Details: Definition of hash-table class.
 */
#include <vector>
#include "../singly-linked-list/singly-linked-list.h"

#pragma once
 class HashTable {
   friend std::ostream& operator<<(std::ostream& os, HashTable HashTableInstance);
   public:
    HashTable();
    HashTable(unsigned int tableLength);
    void Add(int data);
    bool Remove(int data);
    int Length();
    SinglyLinkedList Index(int index);

   private:
    unsigned int LENGTH;
    std::vector<SinglyLinkedList> TableArray;
    std::hash<int> int_hash;
 };