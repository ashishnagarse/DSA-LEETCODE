class Solution {
public:

    // Define a large prime number to take modulo and avoid overflow
    int M = 1000000007;

    // Memoization table to store intermediate results
    int t[1001];

    // Recursive function to solve the problem using memoization
    int solve(int n){

        // Base Case: only 1 way to tile 2x1 — using a vertical domino
        if(n == 1) return 1;

        // Base Case: two ways to tile 2x2 — two vertical dominoes or two horizontal dominoes
        if(n == 2) return 2;

        // Base Case: five ways to tile 2x3 board
        // These include combinations of vertical, horizontal dominoes, and L-trominoes
        if(n == 3) return 5;

        // If result is already computed, return it to avoid redundant computation
        if(t[n] != -1) return t[n];

        // Recursive relation:
        // - 2 * solve(n - 1): adding a vertical domino or two configurations using trominoes
        // - solve(n - 3): complex tromino-based arrangements that fill 3 columns at once
        return t[n] = (2 * solve(n - 1) % M + solve(n - 3) % M) % M;
    }

    // Main function that initializes memoization table and calls the solver
    int numTilings(int n) {
        // Initialize memoization table with -1 (uncomputed state)
        memset(t, -1, sizeof(t));

        // Compute the number of ways to tile a 2 x n board
        return solve(n);
    }
};
