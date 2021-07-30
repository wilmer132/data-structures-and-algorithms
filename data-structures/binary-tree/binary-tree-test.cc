/*
  File: binary-tree-test.cc
  Details: Testing of binary tree class.
 */
#include "binary-tree.h"
#include <iostream>

int main() {
  int Numbers[8] = {5, 7, 3, 8, 1, 9, 2, 10};
  BinaryTree MyBinaryTree = BinaryTree(6);
  std::cout << MyBinaryTree << std::endl;
  for (int i = 0; i < 8; i++) {
    MyBinaryTree.Add(Numbers[i]);
  }
  std::cout << MyBinaryTree << std::endl;
  return 1;
}