/*--------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    bool checkEating(vector<int> &piles, int h, int k){
        long totalHours = 0;
        for(int i : piles){
            totalHours += (i / k);
            totalHours += (i % k != 0);
        }
        return totalHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = -1e9, ans = -1;
        for(int i : piles) high = max(high, i);
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(checkEating(piles, h, mid)){
                high = mid - 1;
                ans = mid;
            }
            else low = mid + 1;
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/koko-eating-bananas/
Author: M.R.Naganathan
*/
