/*
  File: binary-tree.cc
  Details: Implementation of binary tree class.
 */
#include "binary-tree.h"
#include "../node/node.h"

BinaryTree::BinaryTree() {
  LENGTH = INIT_SIZE;
  BinaryTreeArray = new int[LENGTH];
  sizeFilled = 0;
  std::fill_n(BinaryTreeArray, LENGTH, -1);
}

BinaryTree::BinaryTree(int data) {
  LENGTH = INIT_SIZE;
  BinaryTreeArray = new int[LENGTH];
  sizeFilled = 1;
  std::fill_n(BinaryTreeArray, LENGTH, -1);
  ROOT = data;
}

void BinaryTree::ResizeArray() {
  int newLength = LENGTH * 2;
  int* newBinaryTreeArray = new int[newLength];
  std::fill_n(newBinaryTreeArray, newLength, -1);
  memcpy(newBinaryTreeArray, BinaryTreeArray, LENGTH*sizeof(int));
  LENGTH = newLength;
  delete [] BinaryTreeArray;
  BinaryTreeArray = newBinaryTreeArray;
}

void BinaryTree::AddToLeaf(int ItemLoc, int newData) {
  if (ItemLoc >= LENGTH) {
    ResizeArray();
  }
  int BTIndex = ItemLoc - 1;
  if (BinaryTreeArray[BTIndex] == -1) {
    BinaryTreeArray[BTIndex] = newData;
    return;
  }
  if (newData == BinaryTreeArray[BTIndex]) {
    throw("Error: Cannot have duplicate values in Binary Tree");
  } else if (newData < BinaryTreeArray[BTIndex]) {
    AddToLeaf(LEFTCHILD(ItemLoc), newData);
  } else {
    AddToLeaf(RIGHTCHILD(ItemLoc), newData);
  }
}

void BinaryTree::Add(int newData) {
  if (newData < 0) {
    throw("Error: Cannot have negative values in Binary Tree");
  }
  if (sizeFilled == 0) {
    ROOT = newData;
  } else {
    AddToLeaf(1, newData);
  }
  sizeFilled++;
}

// void BinaryTree::NodeMatchParent(Node<int>* currentNode, Node<int>*& nodeToLoad, int nodeData) {
//   if (currentNode == nullptr) {
//     throw("Error: Data to delete does not exist in binary tree");
//   } else if (nodeData == currentNode->value) {
//     nodeToLoad = currentNode;
//     return;
//   } else if (nodeData < currentNode->value) {
//     NodeMatchParent(currentNode->back, nodeToLoad, nodeData);
//   } else if (nodeData > currentNode->value) {
//     NodeMatchParent(currentNode->next, nodeToLoad, nodeData);
//   }
// }

// void BinaryTree::Remove(int deleteData) {
//   if (LENGTH == 0) {
//     throw("Error: Cannot remove data from empty binary tree");
//   } else if (LENGTH == 1) {
//     root = nullptr;
//     LENGTH--;
//     return;
//   }
//   Node<int>* parentOfDeleteNode = new Node<int>();
//   NodeMatchParent(root, parentOfDeleteNode, deleteData);
//   Node<int>* nodeToDelete = (parentOfDeleteNode->value < deleteData) ? parentOfDeleteNode->back : parentOfDeleteNode->next;
//   if (nodeToDelete->back == nullptr && nodeToDelete->next == nullptr) {
//     if (parentOfDeleteNode->value < deleteData) {
//       parentOfDeleteNode->back = nullptr;
//     } else {
//       parentOfDeleteNode->next = nullptr;
//     }
//   } else if ((nodeToDelete->back != nullptr && nodeToDelete->next == nullptr) || 
//             (nodeToDelete->back == nullptr && nodeToDelete->next != nullptr)) {
//     if (parentOfDeleteNode->value < deleteData) {
//       parentOfDeleteNode->back = (nodeToDelete->back != nullptr) ? nodeToDelete->back: nodeToDelete->next;
//     } else {
//       parentOfDeleteNode->next = (nodeToDelete->back != nullptr) ? nodeToDelete->back: nodeToDelete->next;
//     }
//   } else {
//     Node<int>* ParentOfPreDecessor = InOrderPreDecessor(nodeToDelete);
//   }
//   delete nodeToDelete;
//   LENGTH--;
// }
void BinaryTree::InOrderTraversalString(int currentLoc, std::string& currentString) {
  int currentIndex = currentLoc - 1;
  if (currentIndex > LENGTH || BinaryTreeArray[currentIndex] == -1) {
    return;
  }
  InOrderTraversalString(LEFTCHILD(currentLoc), currentString);
  currentString += std::to_string(BinaryTreeArray[currentIndex]) + " ";
  InOrderTraversalString(RIGHTCHILD(currentLoc), currentString);
}

std::ostream& operator<<(std::ostream& os, BinaryTree BinaryTreeInstance) {
  os << "[";
  std::string BinaryTreeInstanceString = "";
  BinaryTreeInstance.InOrderTraversalString(1, BinaryTreeInstanceString);
  os << BinaryTreeInstanceString;
  os << "]";
  return os;
}