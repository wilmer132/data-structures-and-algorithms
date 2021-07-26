/*
  File: node.cc
  Details: Implementation of node class
 */
#include "node.h"

template<class NodeData>
Node<NodeData>::Node() {
  next = nullptr;
  nodeHash = -1;
}

template<class NodeData>
Node<NodeData>::Node(NodeData data, int dataHash) {
  next = nullptr;
  value = data;
  nodeHash = dataHash;
}

std::ostream& operator<<(std::ostream& os, Node<std::string> DataNode) {
  os << "{Value: " << DataNode.value << ", Hash: " << DataNode.nodeHash << ", Next: " << DataNode.next << "}";
  return os; 
}

std::ostream& operator<<(std::ostream& os, Node<int> DataNode) {
  os << "{Value: " << DataNode.value << ", Hash: " << DataNode.nodeHash << ", Next: " << DataNode.next << "}";
  return os; 
}

template class Node<std::string>;
template class Node<int>;