/*
Example:
Input:  s = "6759"
All possible substrings:
6, 7, 5, 9, 67, 75, 59, 675, 759, 6759
Sum = 6 + 7 + 5 + 9 + 67 + 75 + 59 + 675 + 759 + 6759 = 8421
Output: 8421

Approach:
- Traverse the string from right to left.
- Use a multiplier factor (mf) to calculate each digit's contribution to all substrings it participates in.
- Update mf as (mf * 10 + 1) for next iteration, reflecting its increasing place value.
*/

class Solution {
  public:
    int sumSubstrings(string &s) {
        long long int sum = 0;  // Total sum of all substrings
        long long int mf = 1;   // Multiplier factor for digit's contribution
        int MOD = 1000000007;   // Optional MOD if needed for large inputs (not required here)

        // Traverse the string from right to left
        for (int i = s.size() - 1; i >= 0; i--) {
            int digit = s[i] - '0';  // Convert char to integer

            // Contribution of s[i] to all substrings it's part of
            sum += digit * (i + 1) * mf;

            // Update the multiplier factor for the next digit to the left
            mf = mf * 10 + 1;
        }

        // Return the total sum (modulo optional, not used since 32-bit int is guaranteed)
        return static_cast<int>(sum);
    }
};
