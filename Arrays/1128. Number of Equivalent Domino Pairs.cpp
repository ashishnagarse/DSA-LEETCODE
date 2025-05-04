#include <vector>
#include <unordered_map>
#include <algorithm>  // For min and max
using namespace std;

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    // Hash map to store the frequency of each normalized domino
    unordered_map<int, int> count;
    
    // Variable to keep track of the total number of equivalent pairs
    int result = 0;

    // Iterate through each domino
    for (auto& d : dominoes) {
        // Normalize the domino by ordering the values (smaller number first)
        int a = min(d[0], d[1]);
        int b = max(d[0], d[1]);

        // Encode the normalized domino as a unique integer key
        // Since values are in range [1, 9], a*10 + b gives a unique key for each unordered pair
        int key = a * 10 + b;

        // Add the current number of times we've seen this domino to the result
        // For example, if we've seen this key 2 times already, this new one forms 2 new pairs
        result += count[key];

        // Increment the count for this normalized domino
        count[key]++;
    }

    // Return the total number of equivalent domino pairs
    return result;
}
