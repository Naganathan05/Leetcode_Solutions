/*------------------------------
  Time Complexity: O(k * logn)
  Space Complexity: O(n)
---------------------------------*/

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long totalScore = 0;
        priority_queue<int> maxHeap;
        for(int i : nums) maxHeap.push(i);

        while(k){
            int maxElement = maxHeap.top();
            maxHeap.pop();
            totalScore += maxElement;
            maxHeap.push(ceil(maxElement / 3.0));
            k -= 1;
        }
        return totalScore;
    }
};

/*
Question Link: https://leetcode.com/problems/maximal-score-after-applying-k-operations/
Author: M.R.Naganathan
*/
