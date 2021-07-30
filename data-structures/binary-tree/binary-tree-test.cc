/*
  File: binary-tree-test.cc
  Details: Testing of binary tree class.
 */
#include "binary-tree.h"
#include <iostream>

int main() {
  try {
    int Numbers[8] = {5, 7, 3, 8, 1, 10, 9, 11};

    std::cout << "Initializing Binary Tree..." << std::endl;
    BinaryTree MyBinaryTree = BinaryTree(6);
    std::cout << "Binary Tree now: " << MyBinaryTree << std::endl;

    std::cout << "Adding values to Binary Tree..." << std::endl;
    for (int i = 0; i < 8; i++) {
      MyBinaryTree.Add(Numbers[i]);
    }
    std::cout << "Binary Tree now: " << MyBinaryTree << std::endl;

    std::cout << "Removing values from Binary Tree..." << std::endl;
    // MyBinaryTree.Remove(10);
    // MyBinaryTree.Remove(7);
    // MyBinaryTree.Remove(5);
    for (int i = 0; i < 8; i++) {
      MyBinaryTree.Remove(Numbers[i]);
      std::cout << "Binary Tree now: " << MyBinaryTree << std::endl;
    }
    MyBinaryTree.Remove(6);
    std::cout << "Binary Tree now: " << MyBinaryTree << std::endl;
  } catch (const char* errorMessage) {
    std::cout << errorMessage << std::endl;
  }
  return 1;
}