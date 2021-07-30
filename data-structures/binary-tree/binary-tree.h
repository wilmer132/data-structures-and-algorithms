/*
  File: binary-tree.h
  Details: Definition of binary tree class.
 */
#include <string>

#define INIT_SIZE 10
#define ROOT BinaryTreeArray[0]
#define PARENT(i) (i / 2)
#define LEFTCHILD(i) (i*2)
#define RIGHTCHILD(i) ((i*2) + 1)

#pragma once
class BinaryTree {
  friend std::ostream& operator<<(std::ostream& os, BinaryTree BinaryTreeInstance);
  public:
    int* BinaryTreeArray;

    BinaryTree();
    BinaryTree(int data);
    void Add(int newData);
    void Remove(int deleteData);
    void InOrderTraversal();
    void PreOrderTraversal();
    void PostOrderTraversal();
    void InOrderTraversalString(int currentLoc, std::string& currentString);
  private:
    int LENGTH;
    int sizeFilled;
    
    void AddToLeaf(int ItemLoc, int newData);
    void ResizeArray();
    // void NodeMatchParent(Node<int>* currentNode, Node<int>*& nodeToLoad, int nodeData);
};