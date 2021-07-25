/*
  File: hash-table.h
  Details: Definition of hash-table class.
 */
#include <vector>
#include <string>
#include "../singly-linked-list/singly-linked-list.h"

#pragma once
 class HashTable {
   public:
    HashTable();
    HashTable(unsigned int tableLength);
    void Add(std::string data);

   private:
    unsigned int LENGTH;
    std::vector<SinglyLinkedList> TableArray;
    std::hash<std::string> string_hash;
 };