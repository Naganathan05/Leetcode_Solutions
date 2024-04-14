/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-------------------------------------------------*/

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int mini = INT_MAX, max_diff = INT_MIN;
        for(int i = 0; i <= nums.size() - 1; i++){
            if(isPrime(nums[i])){
                mini = min(mini, i);
                max_diff = max(max_diff, (i - mini));
            }
        }
        return max_diff;
    }

    bool isPrime(int n){
        if (n <= 1) return false;
        
        for (int i = 2; i <= n / 2; i++){
            if (n % i == 0) return false;
        }
        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-prime-difference/
Author: M.R.Naganathan
*/
