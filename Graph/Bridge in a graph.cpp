class Solution {
  public:
    void dfs( int c , unordered_map<int , vector<int>>& adj , vector<bool>& visited ){
        
        visited[c] = true;
        
        for(auto& ngbr : adj[c]){
            
            if(!visited[ngbr] ){
                dfs(ngbr , adj , visited);
            }
        }
        
    }
    
    
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        
        unordered_map<int , vector<int>> adj ;

        
        
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        auto& cList = adj[c];
        cList.erase( remove(cList.begin() , cList.end() , d) , cList.end() );
        
        auto& dList = adj [d];
        dList.erase(  remove(dList.begin() , dList.end() , c)    , dList.end());
        
        vector<bool> visited(V , false);
        dfs(c , adj , visited);
        
        return (!visited[d]);
        
        
    }
};
