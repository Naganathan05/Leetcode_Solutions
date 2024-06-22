/*------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------------------*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (atmost(nums, k) - atmost(nums, k - 1));
    }

    int atmost(vector<int>& nums, int k){
        int numOdd = 0, numSubarray = 0, i = 0;
        for(int j = 0; j <= nums.size() - 1; j++){
            if(nums[j] % 2) numOdd += 1;
            while(numOdd > k && i <= nums.size() - 1){
                if(nums[i] % 2) numOdd -= 1;
                i += 1;
            }
            numSubarray += (j - i + 1);
        }
        return numSubarray;
    }
};

/*
Question Link: https://leetcode.com/problems/count-number-of-nice-subarrays/
Author: M.R.Naganathan
*/
