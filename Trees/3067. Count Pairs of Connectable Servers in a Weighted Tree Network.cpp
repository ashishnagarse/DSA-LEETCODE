class Solution {
public:

    unordered_map<int , vector<pair<int , int>>> gr;  // Adjacency list for the graph: node -> list of (neighbor, distance)
    int ss, n , ct;  // ss = signal speed, n = number of nodes, ct = counter for valid paths

    // Depth-First Search function to count valid paths from a node
    void dfs(int node , int par , int d){
        // If total distance from source is divisible by signalSpeed, count it
        if(d % ss == 0) ct++;

        // Traverse all children (neighbors), skipping the parent
        for(auto [ch , dis] : gr[node]){
            if(ch != par){
                dfs(ch , node , d + dis);  // Recursive DFS with updated distance
            }
        }
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        
        int n = edges.size() + 1;  // Number of nodes is one more than number of edges in a tree
        ss = signalSpeed;          // Set global signalSpeed

        // Build the undirected graph
        for(auto vec : edges){
            int u = vec[0];
            int v = vec[1];
            int d = vec[2];  // Distance between nodes u and v

            gr[u].push_back({v , d});
            gr[v].push_back({u , d});
        }

        vector<int> fans(n, 0);  // Final answer vector: result for each node

        // For each node, act as root and compute connectable pairs
        for(int par = 0 ; par < n ; par++){

            int ans = 0, sum = 0;
            vector<int> temp;  // To store count of valid paths from each neighbor

            // Traverse each neighbor of the current node
            for(auto [ch , d] : gr[par]){
                ct = 0;  // Reset count for this DFS traversal
                dfs(ch , par , d);  // DFS from neighbor with initial distance
                temp.push_back(ct);  // Store the result
                sum += ct;  // Sum up all counts
            }

            // Now compute the number of unique valid pairs from different branches
            // Formula: For counts [a, b, c], total = (a*b + a*c + b*c) = sum_over_all_pairs(a_i * a_j) for i < j
            for(auto el : temp){
                ans += (sum - el) * el;
                fans[par] = ans / 2;  // Divide by 2 to avoid double counting
            }
        }

        return fans;
    }
};
