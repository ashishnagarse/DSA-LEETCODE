class Solution {
public:
    // Define 4 possible directions of movement: up, down, right, and left
    vector<vector<int>> directions = { {-1,0} , {1,0} , {0,1} , {0,-1} };
    
    // Use a priority queue node type: {time, {row, col}}
    typedef pair<int , pair<int , int>> P;

    int minTimeToReach(vector<vector<int>>& moveTime) {

        int m = moveTime.size();      // Number of rows
        int n = moveTime[0].size();   // Number of columns

        // Store the minimum time to reach each cell, initialized to INT_MAX
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        // Min-heap to always process the cell with the smallest arrival time
        priority_queue<P, vector<P>, greater<P>> pq;

        // Starting point at top-left corner (0, 0) with 0 time
        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            // Get the cell with the smallest current time
            int currTime = pq.top().first;
            pair<int, int> cell = pq.top().second;
            int i = cell.first;
            int j = cell.second;
            pq.pop();

            // If we reached the destination (bottom-right corner), return the time
            if (i == m - 1 && j == n - 1) {
                return currTime;
            }

            // Explore all 4 adjacent cells
            for (auto& dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                // Check if the next cell is within bounds
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
                    
                    // Wait time needed to enter the cell if arriving too early
                    int wait = max(moveTime[i_][j_] - currTime, 0);

                    // Calculate arrival time: current time + wait + 1 (for movement)
                    int arrivalTime = currTime + wait + 1;

                    // If this path gives a shorter time to reach (i_, j_), update it
                    if (result[i_][j_] > arrivalTime) {
                        result[i_][j_] = arrivalTime;
                        pq.push({arrivalTime, {i_, j_}});
                    }
                }
            }
        }

        // If destination cannot be reached (shouldn't happen if input is valid)
        return -1;
    }
};
