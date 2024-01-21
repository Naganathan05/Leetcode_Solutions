/*------------------------------------------------------------
  Time Complexity: O(nlogk)  => n:Number Elements in the array
  Space Complexity: O(n)
--------------------------------------------------------------*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i = 0; i <= nums.size() - 1; i++){
            freq[nums[i]]++;
        }
        // Min Heap for storing the frequency values in sorted order
        priority_queue<pair<int, int>> queue;
        for(auto i : freq){
            queue.push(pair{i.second, i.first});
        }
        vector<int> ans;
        for(int i = 0; i <= k - 1; i++){
            ans.push_back(queue.top().second);
            queue.pop();
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/top-k-frequent-elements/description/
Author: M.R.Naganathan
*/
