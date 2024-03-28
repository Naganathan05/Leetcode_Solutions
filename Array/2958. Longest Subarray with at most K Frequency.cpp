/*--------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-----------------------------------------------*/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> freq;
        int flag = 0, i = 0, j = 0;
        int max_len = 0;
        while(j <= nums.size() - 1 && i <= j){
            if(flag){
                freq[nums[i]] -= 1;
                i += 1;
            }
            else{
                freq[nums[j]] += 1;
                j += 1;
            }

            flag = 0;
            if(freq[nums[j - 1]] > k) flag = 1;
            if(flag == 0){
                max_len = max(max_len, (j - i));
            }
        }
        return max_len;
    }
};

/*
Question Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
Author: M.R.Naganathan
*/
