/*-----------------------------------
  Time Complexity: O(nlogn + qlogn)
  Space Complexity: O(n)
-------------------------------------*/

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        long long totalSum = 0;
        for(int i = 0; i <= nums.size() - 1; i++){
            totalSum += nums[i];
            minHeap.push({nums[i], i});
        }
        vector<bool> visited(nums.size(), false);
        vector<long long> answer;

        for(auto query : queries){
            int ind = query[0], currK = query[1];
            if(!visited[ind]){
                visited[ind] = true;
                totalSum -= nums[ind];
            }

            while(!minHeap.empty() && currK){
                int currInd = minHeap.top().second;
                minHeap.pop();

                if(visited[currInd]) continue;
                visited[currInd] = true;
                totalSum -= nums[currInd];
                currK -= 1;
            }
            answer.push_back(totalSum);
        }
        return answer;
    }
};

/*
Question Link: https://leetcode.com/problems/mark-elements-on-array-by-performing-queries/
Author: M.R.Naganathan
*/
