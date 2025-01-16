/*----------------------------
  Time Complexity: O(nlogk)
  Space Complexity: O(k)
------------------------------*/

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int numRewards = reward1.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i = 0; i <= numRewards - 1; i++){
            minHeap.push({reward1[i] - reward2[i], i});
            if(minHeap.size() > k) minHeap.pop();
        }

        int maxScore = 0;
        while(!minHeap.empty()){
            int ind = minHeap.top().second;
            minHeap.pop();
            reward2[ind] = INT_MIN;
            maxScore += reward1[ind];
        }

        for(int i = 0; i <= numRewards - 1; i++){
            if(reward2[i] != INT_MIN) maxScore += reward2[i];
        }
        return maxScore;
    }
};

/*
Question Link: https://leetcode.com/problems/mice-and-cheese/
Author: M.R.Naganathan
*/
