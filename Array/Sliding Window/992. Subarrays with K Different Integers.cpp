/*------------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------------------------------*/

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }

    int atmost(vector<int> nums, int k){
        int j = 0, i = 0, result = 0, unique = 0;
        unordered_map<int, int> freq;
        for(int j = 0; j <= nums.size() - 1; j++){
            freq[nums[j]] += 1;
            if(freq[nums[j]] == 1) unique += 1;
            while(i <= j && unique > k && i < nums.size()){
                freq[nums[i]] -= 1;
                if(freq[nums[i]] == 0) unique -= 1;
                i += 1;
            }
            result += (j - i + 1);
        }
        return result;
    }
};

/*
Question Link: https://leetcode.com/problems/subarrays-with-k-different-integers/
Author: M.R.Naganathan
*/
