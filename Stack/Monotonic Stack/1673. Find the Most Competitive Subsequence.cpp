/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> filo;
        for(int i = 0; i <= nums.size() - 1; i++){
            int currNum = nums[i];
            int remNumbers = filo.size() - 1 + nums.size() - i;
            while(!filo.empty() && nums[filo.top()] > currNum && remNumbers >= k){
                filo.pop();
                remNumbers -= 1;
            }
            if(filo.size() < k) filo.push(i);
        }

        vector<int> answer;
        while(!filo.empty()){
            answer.push_back(nums[filo.top()]);
            filo.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-most-competitive-subsequence/
Author: M.R.Naganathan
*/
