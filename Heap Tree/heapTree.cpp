#include <iostream>
using namespace std;

// HEAP TREE
// Min heap, the key present at the root node must be greatest among the keys present at all its children

//    Min heap               Max heap
//       10                     100
//   15      30             40      50
// 40 50   100 40         10 15     50 40

// A heap is an array that can be views as a complete binary tree

// Find the parents and children
// Parent(i) = floor(i/2) (redondear hacia abajo)
// Left(i) = 2i
// Right(i) = 2i + 1

// To create the max heap
// 1. Create a new node at the end if heap
// 2. Assign the new value to the node
// 3. Compare the value of this child node with its parent
// 4. If value of parent is less than child, then swap them
// 5. Repear step 3 & 4 until Heap property holds

// Delete head

// DFS y BFS

// Depth-first search
// Iterate until the stack is empty (with an array you can implement a stack)

// Breadth First Search
// Iterate by levels
