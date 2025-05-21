class Solution {
  public:
  
    // Helper function to count how many numbers are ≤ ele in the m x n multiplication table
    int lowThanK(int ele , int m , int n){
        int sum = 0;
        for(int i = 1 ; i <= m; i++){
            // For each row i, numbers are: i*1, i*2, ..., i*n
            // Count how many are ≤ ele → at most ele / i numbers per row
            // Clamp it to n, because we can't have more than n columns
            sum += min(ele / i, n);
        }
        return sum;
    }
    
    // Main function to find the k-th smallest number in the m x n multiplication table
    int kthSmallest(int m, int n, int k) {
        int low = 1;         // Smallest possible value in the table
        int high = m * n;    // Largest possible value in the table
        
        // Binary search to find the smallest number such that
        // there are at least k numbers ≤ that number
        while(low <= high){
            int mid = low + (high - low) / 2;

            // Count of numbers less than or equal to mid
            if(lowThanK(mid , m , n) < k){
                // Not enough numbers ≤ mid, go right
                low = mid + 1;
            }
            else{
                // Too many or just enough numbers ≤ mid, try to go smaller
                high = mid - 1;
            }
        }

        // low is the smallest number such that there are at least k numbers ≤ low
        return low;
    }
};
