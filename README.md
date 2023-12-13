# Final Project Advanced Data Structures and Algorithms

## Problem 1: Connected region
```
Given a matrix with (x,y) being the position/cell containing the element located on row x column y (x, y ≥
0). A path to move from a position (x, y) to (x',y') according to a given rule
before and each move can only go to adjacent cells (same row or same
column), then we call (x,y) and (x', y') connected to each other. A connected region is a set of all
all positions that from one position in the set can go to any position in the same set
there. Write a program that implements the following requirements:

  a) Input matrix A (MxN) from the text file named inpLT.txt with the structure
  as follows:
    • First line of 2 numbers M, N (M, N ≤ 100)
    • The next M lines, each line contains N characters 'O' or 'X'

  b) Determine connected regions for positions containing X characters and number them
  similarly for connected regions.

  c) Export to a text file named outLT.txt the number of connected regions containing only 1 cell and
  non-negative integer matrix B (MxN) according to the rule B[i][j] = 0 if
  A[i][j]= ‘O’ and B[i][j] = sequence number of the connected region containing position (i,j) if
  A[i][j]= ‘X’.
```
### Example
![Output](/img/example1.png)

### DFS Algorithm:
The DFS (Depth-First Search) algorithm is a graph traversal algorithm that uses a hierarchical approach
depth. It starts from a starting vertex, then follows a specific branch until it reaches zero
can continue anymore. Then it goes back and tries another branch.

### Function to check position
```c++
bool testxy(int x, int y, int M, int N) {
  return (x >= 0 && x < M && y >= 0 && y < N);
}
```
### Function DFS
```c++
void dfs(int x, int y, int mark, int M, int N, char A[100][100], int B[100][100], int& count) {
  B[x][y] = mark;
  count++;

  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};

  for (int i = 0; i < 4; ++i) {
    int newX = x + dx[i];
    int newY = y + dy[i];11

    if (testxy(newX, newY, M, N) && A[newX][newY] == 'X' && B[newX][newY] == 0) {
      dfs(newX, newY, mark, M, N, A, B, count);
    }
  }
}
```
## Problem 2: Binary search tree
```
Write a program using binary search tree (BST) to perform:

  a) Import from a text file named inpLN.txt with the following structure:
    • The first line contains a number N (N ≤ 105)
    • The next line is an array A consisting of N elements, each element is a non-negative integer
    does not exceed 109.
    • The third line contains a number M (M ≤ 103)
    • The next M lines each contain an integer K (K ≤ 109).

  b) Output the output file named outLN.txt M lines corresponding to the last M lines of the input file, each
  row is the largest number in the tree that does not exceed K.
```
### Example
![Output](/img/example2.png)
### Binary Search Tree
The Binary Search Tree (BST) algorithm is a special, designed binary tree data structure
to support efficient searching and sorting of data. Below are details about the operations
Basics and complexity of BST:
Collection Structure:
Each node in the BST has two children, one on the left and one on the right. The button on the left has a small value
than the parent node, and the right node has a value greater than the parent node.
### Create a new button
```c++
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
```
### Inserts a value into the BST
``` c++
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}
```
### Searches for a value in the BST
``` c++
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == value) {
        return true;
    }

    if (value < root->data) {
        return search(root->left, value);
    }

    return search(root->right, value);
}
```

