/*--------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-----------------------------------*/

class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int j = 0, i = 0, result = 0, unique = 0;
        unordered_map<int, int> freq;
        for(int j = 0; j <= nums.size() - 1; j++){
            freq[nums[j]] += 1;
            if(freq[nums[j]] == 1) unique += 1;
            while(i <= j && unique > 2 && i < nums.size()){
                freq[nums[i]] -= 1;
                if(freq[nums[i]] == 0) unique -= 1;
                i += 1;
            }
            result = max(result, (j - i + 1));
        }
        return result;
    }
};

/*
Question Link: https://leetcode.com/problems/fruit-into-baskets/
Author: M.R.Naganathan
*/
