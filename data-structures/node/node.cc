/*
  File: node.cc
  Details: Implementation of node class
 */

#include "node.h"

Node::Node(std::string data) {
  next = nullptr;
  value = data;
}