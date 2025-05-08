class Solution {
public:
    // Each state in our priority queue is represented as a tuple:
    // (current total time, row index, column index, step parity)
    typedef tuple<int, int, int, int> State;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();       // number of rows
        int n = moveTime[0].size();    // number of columns

        // result[i][j][parity] stores the minimum time to reach (i, j)
        // with the given step parity: 0 (even step), 1 (odd step)
        vector<vector<vector<int>>> result(m, vector<vector<int>>(n, vector<int>(2, INT_MAX)));

        // Min-heap priority queue to always expand the node with the least time first
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0, 0, 0, 0}); // Start at (0, 0) at time 0 with even step (parity = 0)

        // 4-directional movement: up, down, left, right
        vector<vector<int>> directions = { {-1,0}, {1,0}, {0,-1}, {0,1} };

        // Starting point is reached at time 0 with even step
        result[0][0][0] = 0;

        // Dijkstra-style BFS: always pick the state with the least time next
        while (!pq.empty()) {
            auto [time, i, j, parity] = pq.top(); // Unpack the state
            pq.pop();

            // If we reached the bottom-right cell, return the time taken
            if (i == m-1 && j == n-1) return time;

            for (auto& dir : directions) {
                int ni = i + dir[0]; // new row
                int nj = j + dir[1]; // new column

                // Stay within the grid bounds
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    // Step cost: alternate between 1 and 2 depending on parity
                    int moveCost = (parity == 0) ? 1 : 2;

                    // You may need to wait at the destination cell until its available time
                    int waitTime = max(moveTime[ni][nj] - (time), 0);

                    // Total time to reach the new cell
                    int arrivalTime = time + moveCost + waitTime;

                    // Alternate the parity for the next move
                    int nextParity = 1 - parity;

                    // If this path gets us to (ni, nj) faster with this step parity, take it
                    if (arrivalTime < result[ni][nj][nextParity]) {
                        result[ni][nj][nextParity] = arrivalTime;
                        pq.push({arrivalTime, ni, nj, nextParity});
                    }
                }
            }
        }

        // Return the minimum time to reach the goal with either parity
        return min(result[m-1][n-1][0], result[m-1][n-1][1]);
    }
};
