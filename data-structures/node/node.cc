/*
  File: node.cc
  Details: Implementation of node class
 */

#include "node.h"

Node::Node() {
  next = nullptr;
  value = nullptr;
}

Node::Node(std::string data) {
  next = nullptr;
  value = data;
}

std::ostream& operator<<(std::ostream& os, Node DataNode) {
  os << "{Node Value: " << DataNode.value << ", Next Node: " << DataNode.next << "}";
  return os; 
}