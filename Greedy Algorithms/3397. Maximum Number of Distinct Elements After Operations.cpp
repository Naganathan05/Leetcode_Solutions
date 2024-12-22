/*----------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-------------------------------*/

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int numDistincts = 0;
        unordered_set<int> seenElements;

        int prevNum = -1e9;

        for(int i = 0; i <= nums.size() - 1; i++){
            int currNum = max(nums[i] - k, prevNum + 1);
            while(currNum <= nums[i] + k && seenElements.find(currNum) != seenElements.end()){
                currNum += 1;
            }
            if(currNum > nums[i] + k) continue;
            seenElements.insert(currNum);
            numDistincts += 1;
            prevNum = currNum;
        }
        return numDistincts;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/
Author: M.R.Naganathan
*/
