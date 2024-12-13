/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i = 0; i <= nums.size() - 1; i++) minHeap.push({nums[i], i});
        vector<bool> visited(nums.size(), false);

        long long score = 0;
        while(!minHeap.empty()){
            auto [currVal, ind] = minHeap.top();
            minHeap.pop();

            if(visited[ind]) continue;
            score += currVal;
            visited[ind] = true;
            if(ind > 0) visited[ind - 1] = true;
            if(ind + 1 < nums.size()) visited[ind + 1] = true;
        }
        return score;
    }
};

/*
Question Link: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/
Author: M.R.Naganathan
*/
