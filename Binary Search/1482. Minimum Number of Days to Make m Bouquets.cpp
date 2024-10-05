/*----------------------------------------
  Time Complexity: O(n * log(max - min))
  Space Complexity: O(1)
------------------------------------------*/

class Solution {
public:
    int calculateBoquets(vector<int> &bloomDay, int k, int minDay){
        int i = 0, numBoquets = 0;
        for(int j = 0; j <= bloomDay.size() - 1; j++){
            if(bloomDay[j] > minDay) i = j + 1;
            if((j - i + 1) == k){
                numBoquets += 1;
                i = j + 1;
            }
        }
        return numBoquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1e9, high = 0;
        for(int i : bloomDay){
            high = max(high, i);
            low = min(low, i);
        }

        int minDays = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int numBoquets = calculateBoquets(bloomDay, k, mid);
            if(numBoquets >= m){
                high = mid - 1;
                minDays = mid;
            }
            else low = mid + 1;
        }
        return minDays;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
Author: M.R.Naganathan
*/
