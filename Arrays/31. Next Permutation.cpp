/*
    Company Tags                 : Amazon, FactSet, Hike, Amazon, MakeMyTrip, Qualcomm, Infosys, Microsoft, Google, Salesforce, Flipkart
    GfG Link                     : https://practice.geeksforgeeks.org/problems/next-permutation5226/1
    Leetcode Qn Link             : https://leetcode.com/problems/next-permutation/
*/

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i = n-2;
        
        while(i>=0 && arr[i]>=arr[i+1]){
            i--;
        }
        if(i>=0){
            int j = n-1;
            while(arr[j]<=arr[i]){
                j--;
            }
            swap(arr[i] , arr[j]);
        }
        reverse(arr.begin()+i+1 , arr.end());
    }
};
