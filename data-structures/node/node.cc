/*
  File: node.cc
  Details: Implementation of node class
 */
#include "node.h"

template<class NodeData>
Node<NodeData>::Node() {
  next = nullptr;
  back = nullptr;
  nodeHash = -1;
}

template<class NodeData>
Node<NodeData>::Node(NodeData data, int dataHash) {
  next = nullptr;
  back = nullptr;
  value = data;
  nodeHash = dataHash;
}

std::ostream& operator<<(std::ostream& os, Node<std::string> DataNode) {
  os << "{Value: " << DataNode.value << ", Hash: " << DataNode.nodeHash << ", Back: " << DataNode.back << ", Next: " << DataNode.next << "}";
  return os; 
}

std::ostream& operator<<(std::ostream& os, Node<int> DataNode) {
  os << "{Value: " << DataNode.value << ", Hash: " << DataNode.nodeHash << ", Back: " << DataNode.back << ", Next: " << DataNode.next << "}";
  return os; 
}

bool operator==(const Node<std::string>& lNode, const Node<std::string>& rNode) {
  return ((lNode.value == rNode.value) && (lNode.nodeHash == rNode.nodeHash));
}

bool operator==(const Node<int>& lNode, const Node<int>& rNode) {
  return ((lNode.value == rNode.value) && (lNode.nodeHash == rNode.nodeHash));
}

template class Node<std::string>;
template class Node<int>;