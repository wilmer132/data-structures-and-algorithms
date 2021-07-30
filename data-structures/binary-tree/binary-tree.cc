/*
  File: binary-tree.cc
  Details: Implementation of binary tree class.
 */
#include <iostream>
#include "binary-tree.h"

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

// void BinaryTree::LeftMostItem(int currentLoc, int& locToLoad) {
//   int leftChildIndex = LEFTCHILD(currentLoc) -1;
//   if (LEFTCHILD(currentLoc) > LENGTH || BinaryTreeArray[leftChildIndex] == -1) {
//     locToLoad = BinaryTreeArray[currentLoc];
//     return;
//   }
//   LeftMostItem(LEFTCHILD(currentLoc), locToLoad);
// }

void BinaryTree::RightMostItem(int currentLoc, int& locToLoad) {
  int rightChildIndex = RIGHTCHILD(currentLoc) - 1;
  if (RIGHTCHILD(currentLoc) > LENGTH || BinaryTreeArray[rightChildIndex] == -1) {
    locToLoad = currentLoc;
    return;
  }
  RightMostItem(RIGHTCHILD(currentLoc), locToLoad);
}

void BinaryTree::DeleteLoc(int currentLoc) {
  // std::cout << "Now at number " << BinaryTreeArray[currentLoc - 1] << std::endl;
  int currentIndex = currentLoc - 1;
  int leftChildIndex = LEFTCHILD(currentLoc) - 1;
  int rightChildIndex = RIGHTCHILD(currentLoc) - 1;
  /*Potential bug, index may be out of bounds*/
  if ((LEFTCHILD(currentLoc) > LENGTH) || 
      (BinaryTreeArray[leftChildIndex] == -1 && BinaryTreeArray[rightChildIndex] == -1)) {
    // std::cout << "Location to delete is either out-of-bounds or no children" << std::endl;
    BinaryTreeArray[currentIndex] = -1;
    return;
  } else if (BinaryTreeArray[leftChildIndex] != -1 && BinaryTreeArray[rightChildIndex] == -1) {
    // std::cout << "Location has left sub-tree only" << std::endl;
    BinaryTreeArray[currentIndex] = BinaryTreeArray[leftChildIndex];
    DeleteLoc(LEFTCHILD(currentLoc));
  } else if (BinaryTreeArray[leftChildIndex] == -1 && BinaryTreeArray[rightChildIndex] != -1) {
    // std::cout << "Location has right sub-tree only" << std::endl;
    BinaryTreeArray[currentIndex] = BinaryTreeArray[rightChildIndex];
    DeleteLoc(RIGHTCHILD(currentLoc));
  } else {
    // std::cout << "Location has both left and right sub-trees" << std::endl;
    int locToDelete = -1;
    RightMostItem(LEFTCHILD(currentLoc), locToDelete);
    // if (locToDelete == -1) {
    //   LeftMostItem(RIGHTCHILD(currentLoc), locToDelete);
    // }
    // std::cout << "Number to delete is: " << BinaryTreeArray[locToDelete - 1] << std::endl;
    int indexToDelete = locToDelete - 1;
    BinaryTreeArray[currentIndex] = BinaryTreeArray[indexToDelete];
    DeleteLoc(locToDelete);
  }
}

void BinaryTree::MatchData(int currentLoc, int& locToLoad, int data) {
  int currentIndex = currentLoc - 1;
  if (currentLoc > LENGTH || BinaryTreeArray[currentIndex] == -1) {
    return;
  }
  if (data == BinaryTreeArray[currentIndex]) {
    locToLoad = currentLoc;
    return;
  }
  int nextLoc = (data < BinaryTreeArray[currentIndex]) ? LEFTCHILD(currentLoc) : RIGHTCHILD(currentLoc);
  MatchData(nextLoc, locToLoad, data);
}

void BinaryTree::Remove(int deleteData) {
  if (sizeFilled == 0) {
    throw("Error: Cannot remove data from empty binary tree");
  } else if (sizeFilled == 1) {
    ROOT = -1;
    sizeFilled--;
    return;
  }

  int deleteItemLoc = -1;
  MatchData(1, deleteItemLoc, deleteData);
  if (deleteItemLoc == -1) {
    throw("Error: Data to delete does not exist in binary tree");
  }
  // std::cout << "Matched number to delete: " << BinaryTreeArray[deleteItemLoc - 1] << std::endl;
  DeleteLoc(deleteItemLoc);
  sizeFilled--;
}

void BinaryTree::InOrderTraversalString(int currentLoc, std::string& currentString) {
  int currentIndex = currentLoc - 1;
  if (currentIndex > LENGTH || BinaryTreeArray[currentIndex] == -1) {
    return;
  }
  InOrderTraversalString(LEFTCHILD(currentLoc), currentString);
  currentString += std::to_string(BinaryTreeArray[currentIndex]) + " ";
  InOrderTraversalString(RIGHTCHILD(currentLoc), currentString);
}

void BinaryTree::PreOrderTraversalString(int currentLoc, std::string& currentString) {
  int currentIndex = currentLoc - 1;
  if (currentIndex > LENGTH || BinaryTreeArray[currentIndex] == -1) {
    return;
  }
  currentString += std::to_string(BinaryTreeArray[currentIndex]) + " ";
  PreOrderTraversalString(LEFTCHILD(currentLoc), currentString);
  PreOrderTraversalString(RIGHTCHILD(currentLoc), currentString);
}

void BinaryTree::PostOrderTraversalString(int currentLoc, std::string& currentString) {
  int currentIndex = currentLoc - 1;
  if (currentIndex > LENGTH || BinaryTreeArray[currentIndex] == -1) {
    return;
  }
  PostOrderTraversalString(LEFTCHILD(currentLoc), currentString);
  PostOrderTraversalString(RIGHTCHILD(currentLoc), currentString);
  currentString += std::to_string(BinaryTreeArray[currentIndex]) + " ";
}

std::ostream& operator<<(std::ostream& os, BinaryTree BinaryTreeInstance) {
  os << "[";
  std::string BinaryTreeInstanceString = "";
  BinaryTreeInstance.InOrderTraversalString(1, BinaryTreeInstanceString);
  os << BinaryTreeInstanceString;
  os << "]";
  return os;
}