#include <iostream>
#include <string>
#include "node.h"
using namespace std;

int main() {
  Node<string> stringNode("My name is Node1");
  cout << stringNode << endl;
  Node<int> intNode(1234);
  cout << intNode << endl;
  cout << "Comparing two equal Nodes:" << endl;
  Node<int> NodeOne = Node<int>(1, 1);
  Node<int> NodeOneCopy = Node<int>(1, 1); 
  Node<int> NodeTwo = Node<int>(2, 2);
  cout << "CopyCat Nodes Comparison: " << (NodeOne == NodeOneCopy) << endl;
  cout << "Unique Nodes Comparison: " << (NodeOne == NodeTwo) << endl;
  return 1;
}