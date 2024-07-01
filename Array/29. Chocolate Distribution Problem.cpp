/*------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
---------------------------------*/

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        int i = 0, j = m - 1;
        long long minDiff = 1e9;
        while(j <= n - 1){
            minDiff = min(minDiff, (a[j] - a[i]));
            i += 1;
            j += 1;
        }
        return minDiff;
    }   
};

/*
Question Link: https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
Author: M.R.Naganathan
*/
