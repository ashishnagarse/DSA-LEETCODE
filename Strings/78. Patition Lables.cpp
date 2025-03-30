//Link : https://leetcode.com/problems/partition-labels/description/?envType=daily-question&envId=2025-03-30
// T.C. = O(N)
// S.C  = O(1)

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26, 0);

        // Step 1: Store the last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<int> result;
        int start = 0, maxLast = 0;

        // Step 2: Partitioning in a single pass
        for (int i = 0; i < s.size(); i++) {
            maxLast = max(maxLast, lastIndex[s[i] - 'a']);

            // If we've reached the furthest occurrence of the current partition
            if (i == maxLast) {
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};
