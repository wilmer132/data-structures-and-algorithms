/*
  File: queue.cc
  Details: Testing of queue class.
 */
#include <iostream>
#include "queue.h"

int main() {
  try {
    std::cout << "Testing Queue construction:" << std::endl;
    Queue<std::string> QueueOne = Queue<std::string>();
    Queue<int> QueueTwo = Queue<int>(420);
    std::cout << "QueueOne: " << QueueOne << std::endl;
    std::cout << "QueueTwo: " << QueueTwo << std::endl;
    std::cout << "Testing Queue adding:" << std::endl;
    for (int i = 0; i < 10; i++) {
      QueueTwo.Add(i*100);
      std::cout << "Queue now: " << QueueTwo << std::endl;
    }
    std::cout << "Testing Queue removing:" << std::endl;
    for (int i = 0; i <= 10; i++) {
      QueueTwo.Remove();
      std::cout << "Queue now: " << QueueTwo << std::endl;
    }
  } catch(const char* errorMessage) {
    std::cout << errorMessage << std::endl;
  }
  return 1;
}