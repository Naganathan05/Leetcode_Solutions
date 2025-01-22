/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------*/

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i : nums) freq[i] += 1;

        int totalUniques = freq.size();
        int completeSubarrays = atmost(nums, totalUniques) - atmost(nums, totalUniques - 1);
        return completeSubarrays;
    }

    int atmost(vector<int> &nums, int k){
        int completeSubarrays = 0, i = 0, currUniques = 0;
        unordered_map<int, int> freq;
        for(int j = 0; j <= nums.size() - 1; j++){
            freq[nums[j]] += 1;
            currUniques += (freq[nums[j]] == 1);
            while(i < nums.size() && currUniques > k){
                freq[nums[i]] -= 1;
                if(freq[nums[i]] == 0) currUniques -= 1;
                i += 1;
            }
            completeSubarrays += (j - i + 1);
        }
        return completeSubarrays;
    }
};

/*
Question Link: https://leetcode.com/problems/count-complete-subarrays-in-an-array/
Author: M.R.Naganathan
*/
