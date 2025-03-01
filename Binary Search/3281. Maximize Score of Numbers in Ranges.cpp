/*-----------------------------------
  Time Complexity: O(nlogn + nlogm)
  Space Complexity: O(1)
-------------------------------------*/

class Solution {
public:
    bool validateDifference(vector<int> &start, int diff, int d){
        long long lastChosen = start[0];
        for(int i = 1; i < start.size(); i++){
            if(lastChosen + diff > (long long) start[i] + d) return false;
            lastChosen = max((int) lastChosen + diff, start[i]);
        }
        return true;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int low = 0, high = start[start.size() - 1] - start[0] + d;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(validateDifference(start, mid, d)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};

/*
Question Link: https://leetcode.com/problems/maximize-score-of-numbers-in-ranges/
Author: M.R.Naganathan
*/
