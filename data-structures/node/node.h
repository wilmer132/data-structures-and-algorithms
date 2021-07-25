/*
  File: node.h
  Details: Definition of node class
 */

#include <iostream>
#include <string>

#pragma once
class Node {
  friend std::ostream& operator<<(std::ostream& os, Node DataNode);
  public:
    Node* next;
    std::string value;

    Node();
    Node(std::string data);
};