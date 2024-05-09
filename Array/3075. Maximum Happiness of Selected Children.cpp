/*-----------------------------------------
  Time Complexity: O(nlogn + min(k, n))
  Space Complexity: O(1)
-------------------------------------------*/

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long maxHap = 0;
        for(int i = 0; i <= k - 1; i++){
            if(happiness[i] - i >= 0) maxHap += (happiness[i] - i);
            else break;
        }
        return maxHap;
    }
};

/*
Question Link: https://leetcode.com/problems/maximize-happiness-of-selected-children/description/
Author: M.R.Naganathan
*/
