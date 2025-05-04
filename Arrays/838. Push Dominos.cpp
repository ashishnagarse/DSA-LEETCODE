#include <iostream>
#include <vector>
#include <string>
using namespace std;

string pushDominoes(string dominoes) {
    int n = dominoes.size();                // Length of the input string
    vector<int> forces(n, 0);               // Force array: positive = rightward force, negative = leftward force

    // LEFT TO RIGHT PASS: Apply rightward force from 'R'
    int force = 0;
    for (int i = 0; i < n; ++i) {
        if (dominoes[i] == 'R') {
            force = n;                      // Maximum force when a rightward push starts
        } else if (dominoes[i] == 'L') {
            force = 0;                      // Leftward domino blocks rightward force
        } else if (force > 0) {
            force--;                        // Force weakens by 1 for each step
        }
        forces[i] += force;                 // Add rightward force (positive)
    }

    // RIGHT TO LEFT PASS: Apply leftward force from 'L'
    force = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (dominoes[i] == 'L') {
            force = n;                      // Maximum force when a leftward push starts
        } else if (dominoes[i] == 'R') {
            force = 0;                      // Rightward domino blocks leftward force
        } else if (force > 0) {
            force--;                        // Force weakens by 1 for each step
        }
        forces[i] -= force;                 // Subtract leftward force (treated as negative)
    }

    // BUILD RESULT: Translate force values into final domino states
    string result;
    for (int f : forces) {
        if (f > 0) {
            result += 'R';                  // Net rightward force
        } else if (f < 0) {
            result += 'L';                  // Net leftward force
        } else {
            result += '.';                  // Balanced or no force
        }
    }

    return result;
}

// Example usage
int main() {
    string input = ".L.R...LR..L..";
    string output = pushDominoes(input);
    cout << "Final State: " << output << endl;  // Output: LL.RR.LLRRLL..
    return 0;
}
