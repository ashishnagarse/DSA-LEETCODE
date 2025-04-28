class Solution {
  public:
    // Helper function that returns a pair:
    // first element -> max sum when INCLUDING this node
    // second element -> max sum when EXCLUDING this node
    pair<int, int> solve(Node* root) {
        
        if (!root) 
            return {0, 0}; // Base case: if node is NULL, both sums are 0
        
        // Recursively solve for left and right subtrees
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        // If we include current node, we cannot include its immediate children
        int include = root->data + left.second + right.second;
        
        // If we exclude current node, we can take maximum of including or excluding its children
        int exclude = max(left.first, left.second) + max(right.first, right.second);
        
        // Return pair of (include, exclude) sums
        return {include, exclude};
    }
    
    // Main function to return the maximum sum of non-adjacent nodes
    int getMaxSum(Node *root) {
        // Get the pair of include and exclude sums from the root
        pair<int, int> ans = solve(root);
        
        // The answer is the maximum of including or excluding the root node
        return max(ans.first, ans.second);
    }
};
