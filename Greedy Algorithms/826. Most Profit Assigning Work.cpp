/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int lowerBound(vector<pair<int, int>> &jobs, int target){
        int st = 0, en = jobs.size() - 1;
        int ans = -1;
        while(st <= en){
            int mid = st + (en - st) / 2;
            if(jobs[mid].first <= target){
                ans = mid;
                st = mid + 1;
            }
            else en = mid - 1;
        }
        return ans;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        int numJobs = difficulty.size();
        for(int i = 0; i <= numJobs - 1; i++) jobs.push_back({difficulty[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        vector<int> maxProfit;
        int currProfit = 0;
        for(int i = 0; i < numJobs; i++){
            currProfit = max(currProfit, jobs[i].second);
            maxProfit.push_back(currProfit);
        }

        int totalProfit = 0;
        for(int i = 0; i < worker.size(); i++){
            int ind = lowerBound(jobs, worker[i]);
            if(ind != -1) totalProfit += maxProfit[ind];
        }
        return totalProfit;
    }
};

/*
Question Link: https://leetcode.com/problems/most-profit-assigning-work/
Author: M.R.Naganathan
*/
