#include <iostream>
#include <string>
#include "node.h"
using namespace std;

int main() {
  Node<string> stringNode("My name is Node1");
  cout << stringNode << endl;
  Node<int> intNode(1234);
  cout << intNode << endl;
  return 1;
}