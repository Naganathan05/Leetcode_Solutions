/*--------------------------
  Time Complexity: O(2^n)
  Space Complexity: O(k)
---------------------------*/

class Solution {
public:
    void allocateJob(vector<int> &jobs, int i, int &k, int currMax, int &globalMax, vector<int> &workerTime){
        if(currMax > globalMax) return;
        if(i == jobs.size()){
            globalMax = min(currMax, globalMax);
            return;
        }

        for(int worker = 0; worker <= k - 1; worker++){
            if (worker > 0 && workerTime[worker] == workerTime[worker - 1]) continue;
            workerTime[worker] += jobs[i];
            allocateJob(jobs, i + 1, k, max(currMax, workerTime[worker]), globalMax, workerTime);
            workerTime[worker] -= jobs[i];
        }
        return;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> workerTime(k, 0);
        int globalMax = 1e9, currMax = 0;
        allocateJob(jobs, 0, k, currMax, globalMax, workerTime);
        return globalMax;
    }
};

/*
Question Link: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/description/
Author: M.R.Naganathan
*/
