/*--------------------------------------------
  Time Complexity: O(n * n) + O(nlogn)
  Space Complexity: O(n)
----------------------------------------------*/

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<float, pair<int, int>>> q;
        for(int i = 0; i <= arr.size() - 1; i++){
            for(int j = i + 1; j <= arr.size() - 1; j++){
                q.push({(float)arr[i]/arr[j], {arr[i], arr[j]}});
                if(q.size() > k) q.pop();
            }
        }
        vector<int> ans(2);
        ans[0] = q.top().second.first;
        ans[1] = q.top().second.second;
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/k-th-smallest-prime-fraction/
Author: M.R.Naganathan
*/
