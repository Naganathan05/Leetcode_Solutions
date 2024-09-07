/*--------------------------
  Time Complexity: O(nlogk)
  Space Complexity: O(k)
-----------------------------*/

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> maxHeap;
        vector<int> results(queries.size(), -1);
        int i = 0;
        for(auto query : queries){
            int currDist = abs(query[0]) + abs(query[1]);
            maxHeap.push(currDist);
            if(maxHeap.size() > k) maxHeap.pop();
            if(maxHeap.size() == k) results[i] = maxHeap.top();
            i += 1;
        }
        return results;
    }
};

/*
Question Link: https://leetcode.com/problems/k-th-nearest-obstacle-queries/
Author: M.R.Naganathan
*/
