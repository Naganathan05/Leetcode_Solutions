/*---------------------------------
  Time Complexity: O(n * log(sum))
  Space Complexity: O(1)
------------------------------------*/

class Solution {
public:
    bool loadPackage(vector<int> &weights, int maxWeight, int days) {
        int currWeight = 0, numDays = 1;
        for(int i = 0; i <= weights.size() - 1; i++) {
            if (currWeight + weights[i] > maxWeight) {
                numDays += 1;
                currWeight = 0;
            }
            currWeight += weights[i];
        }
        return numDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = -1e9, high = 0;
        for(int i : weights){
            high += i;
            low = max(low, i);
        }

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(loadPackage(weights, mid, days)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};

/*
Question Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
Author: M.R.Naganathan
*/
