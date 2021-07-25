/*
  File: node.h
  Details: Definition of node class
 */

#include <iostream>
#include <string>

class Node {
  public:
    Node* next;
    std::string value;

    Node(std::string data);
};