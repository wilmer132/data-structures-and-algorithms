/*
  File: depth-first-search.cc
  Details: Implementation of DFS algorithm
 */

/*
  Assumptions: There exists graph with root node leading
  to other nodes.
*/
template <class Node>
void DFS(Node root) {
  if (root == nullptr) return;
  root.visited = true;
  for (Node neighbor : root.neighbors) {
    if (neighbor.visited == false) {
      DFS(neighbor);
    }
  }
}