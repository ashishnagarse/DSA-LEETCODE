class Solution {
public:
    int subsetXORSum(vector<int>& nums) {

        int result = 0;
        int n = nums.size();

        for(auto& num : nums){
            result|=num;
        }

        return (result<<(n-1));
        
    }
};
