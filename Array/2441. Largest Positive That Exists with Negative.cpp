/*-------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------------------*/

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i : nums) freq[i] += 1;
        int currMax = INT_MIN;
        for(int i : nums){
            if(i > 0 && i > currMax && freq[-i] > 0) currMax = i;
        }
        if(currMax < 0) return -1;
        return currMax;
    }
};

/*
Question Link: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/
Author: M.R.Naganathan
*/
