class Solution {
  public:
    
    void solve(Node* node, vector<int>& path, vector<vector<int>>& result) {
        if (node == NULL)
            return;

        // Add the current node to the path
        path.push_back(node->data);

        // If it's a leaf node, store the path
        if (!node->left && !node->right) {
            result.push_back(path);
        } else {
            // First traverse the left subtree
            if (node->left)
                solve(node->left, path, result);
            
            // Then traverse the right subtree
            if (node->right)
                solve(node->right, path, result);
        }

        // Backtrack to explore other paths
        path.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        vector<int> path;
        solve(root, path, result);
        return result;
    }
};
