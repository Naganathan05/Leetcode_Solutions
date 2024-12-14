/*--------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long numSubarrays = 0;
        int i = 0;
        multiset<int> window;  // To maintain the minimum and maximum values in the window
        
        for (int j = 0; j < nums.size(); ++j) {
            window.insert(nums[j]);
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[i]));
                i += 1;
            }
            numSubarrays += (j - i + 1);
        }
        return numSubarrays;
    }
};

/*
Questtion Link: https://leetcode.com/problems/continuous-subarrays/
Author: M.R.Naganathan
*/
