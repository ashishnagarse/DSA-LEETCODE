/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:

    // Helper function to perform a recursive preorder traversal (Root -> Left -> Right)
    // and collect the left view elements
    void solve(Node* node, int level, vector<int>& res) {
        
        // Base case: if the node is NULL, just return
        if (!node) return;

        // If this is the first time we're visiting this level,
        // then this node is the leftmost node at this level
        if (res.size() == level)
            res.push_back(node->data);

        // Recurse for left subtree first to ensure leftmost nodes are visited first
        solve(node->left, level + 1, res);

        // Then recurse for right subtree
        solve(node->right, level + 1, res);
    }

    // Main function to return the left view of the binary tree
    vector<int> leftView(Node *root) {
        vector<int> res;  // This will store the result (left view nodes)

        // Start recursive traversal from root at level 0
        solve(root, 0, res);

        return res;  // Return the final result
    }
};
