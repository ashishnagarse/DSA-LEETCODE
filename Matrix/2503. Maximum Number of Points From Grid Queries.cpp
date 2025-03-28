class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();


        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end()); // Sort queries

        vector<int> answer(queries.size()); // Result array
        unordered_map<int, int> queryToAnswer; // Map query value to its answer

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        pq.push({grid[0][0], 0}); // {grid_value, linear index}
        visited[0][0] = true;

        int points = 0;

        for (int q : sortedQueries) {
            while (!pq.empty() && pq.top().first < q) {
                auto [val, index] = pq.top();
                pq.pop();

                int i = index / n, j = index % n; // Linear Index to (i, j) Conversion
                points++;

                for (auto& dir : directions) {
                    int ni = i + dir[0], nj = j + dir[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                        pq.push({grid[ni][nj], ni * n + nj}); //  ni * n + nj , (i, j) to Linear Index Conversion
                        visited[ni][nj] = true;
                    }
                }
            }
            queryToAnswer[q] = points;
        }

        // Map sorted queries to original indices
        for (int i = 0; i < queries.size(); i++) {
            answer[i] = queryToAnswer[queries[i]];
        }

        return answer;
    }
};
