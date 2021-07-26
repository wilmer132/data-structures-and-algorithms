/*
  File: node.cc
  Details: Implementation of node class
 */
#include "node.h"

template<class NodeData>
Node<NodeData>::Node() {
  next = nullptr;
}

template<class NodeData>
Node<NodeData>::Node(NodeData data) {
  next = nullptr;
  value = data;
}

std::ostream& operator<<(std::ostream& os, Node<std::string> DataNode) {
  os << "{Node Value: " << DataNode.value << ", Next Node: " << DataNode.next << "}";
  return os; 
}

std::ostream& operator<<(std::ostream& os, Node<int> DataNode) {
  os << "{Node Value: " << DataNode.value << ", Next Node: " << DataNode.next << "}";
  return os; 
}

template class Node<std::string>;
template class Node<int>;