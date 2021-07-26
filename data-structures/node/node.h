/*
  File: node.h
  Details: Definition of node class
 */

#include <iostream>
#include <string>

#pragma once
template <class NodeData>
class Node {
  friend std::ostream& operator<<(std::ostream& os, Node<NodeData> DataNode);
  public:
    Node* next;
    NodeData value;
    int nodeHash;

    Node();
    Node(NodeData data, int dataHash = -1);
};