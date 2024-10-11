/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(k)
---------------------------*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i = 0; i <= nums.size() - 1; i++){
            int currNum = nums[i];
            while(!dq.empty() && dq.back() < currNum) dq.pop_back();
            dq.push_back(currNum);
            if(i >= k && nums[i - k] == dq.front()) dq.pop_front();
            if(i >= k - 1) ans.push_back(dq.front());
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/sliding-window-maximum/
Author: M.R.Naganathan
*/
