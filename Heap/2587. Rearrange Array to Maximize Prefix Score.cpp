/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int score = 0;
        long long totalSum = 0;
        priority_queue<int> maxHeap;
        for(int i : nums){
            if(i > 0){
                totalSum += i;
                score += 1;
            }
            else maxHeap.push(i);
        }

        while(!maxHeap.empty()){
            totalSum += maxHeap.top();
            maxHeap.pop();
            if(totalSum <= 0) return score;
            score += 1;
        }
        return score;
    }
};

/*
Question Link: https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/
Author: M.R.Naganathan
*/
