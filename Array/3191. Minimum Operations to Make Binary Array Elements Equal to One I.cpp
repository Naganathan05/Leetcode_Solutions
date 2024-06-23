/*------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------------------*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int minOp = 0;
        for(int i = 0; i <= nums.size() - 1; i++){
            if(nums[i] == 0){
                if(i + 2 < nums.size()){
                    nums[i] = 1;
                    nums[i + 1] = !nums[i + 1];
                    nums[i + 2] = !nums[i + 2];
                    minOp += 1;
                }
                else return -1;
            }
        }
        return minOp;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/
Author: M.R.Naganathan
*/
