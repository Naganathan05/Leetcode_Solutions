/*--------------------------
  Time Complexity: O(n * d)
  Space Complexity: O(n)
----------------------------*/

class Solution {
public:
    int sumDigits(int num){
        int digitSum = 0;
        while(num){
            digitSum += (num % 10);
            num /= 10;
        }
        return digitSum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSums;

        int maxPairSum = -1;
        for(int i = 0; i <= nums.size() - 1; i++){
            int sum = sumDigits(nums[i]);
            if(digitSums.find(sum) != digitSums.end()){
                maxPairSum = max(maxPairSum, (digitSums[sum] + nums[i]));
                digitSums[sum] = max(digitSums[sum], nums[i]);
            }
            else digitSums[sum] = nums[i];
        }
        return maxPairSum;
    }
};

/*
Question Link: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/
Author: M.R.Naganathan
*/
