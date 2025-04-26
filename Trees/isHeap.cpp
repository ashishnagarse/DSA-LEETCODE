// User Function template for C++

// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
public:
  
    // Function to count the total number of nodes in the binary tree
    int count(Node* tree) {
        if (!tree) return 0; // An empty tree has 0 nodes
        return 1 + count(tree->left) + count(tree->right); // Count current node + left subtree + right subtree
    }
    
    // Function to check if the binary tree satisfies the heap property
    bool solve(Node* tree, int i, int total) {
        if (!tree) return true; // A NULL node is considered valid (base case for recursion)

        if (i >= total) return false; // If index assigned to current node is >= total nodes, it's NOT complete

        // Max Heap Property: Parent must be greater than or equal to its left child
        if (tree->left && tree->data < tree->left->data) return false;

        // Max Heap Property: Parent must be greater than or equal to its right child
        if (tree->right && tree->data < tree->right->data) return false;

        // Recursively check left and right subtrees
        // Left child index = 2*i + 1, Right child index = 2*i + 2 (array representation of binary tree)
        return solve(tree->left, 2*i + 1, total) && solve(tree->right, 2*i + 2, total);
    }
    
    // Main function to check if the binary tree is a heap
    bool isHeap(Node* tree) {
        int total = count(tree); // Step 1: Count the total number of nodes
        return solve(tree, 0, total); // Step 2: Start from index 0 and validate the heap
    }
};
