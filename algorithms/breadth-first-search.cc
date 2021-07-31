/*
  File: breadth-first-search.cc
  Details: Implementation of BFS algorithm
 */

/*
  Assumptions: There exists graph with root node leading
  to other nodes.
*/
template <class Node>
void BFS(Node root) {
  if (root == nullptr) return;
  root.visited = true;
  for (Node neighbor : root.neighbors) {
    if (neighbor.visited == false) {
      BFS(neighbor);
    }
  }
}