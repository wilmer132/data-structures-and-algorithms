/*
  File: breadth-first-search.cc
  Details: Implementation of BFS algorithm
*/

template <class Node, class Queue>
void BFS(Node root) {
  Queue queue = new Queue();
  root.visited = true;
  queue.enqueue(root);
  while (!queue.isEmpty()) {
    Node currentNode = queue.dequeue();

    /*Do work on node*/
    
    for (Node neighbor : currentNode.neighbors) {
      if (!neighbor.visited) {
        neighbor.visited = true;
        queue.enqueue(neighbor);
      }
    }
  }
}