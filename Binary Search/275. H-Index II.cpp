/*--------------------------
  Time Complexity: O(logn)
  Space Complexity: O(1)
----------------------------*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 0, high = citations.size() - 1;
        int maxHVal = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int papersFromMid = citations.size() - mid;
            if(citations[mid] >= papersFromMid){
                maxHVal = papersFromMid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return maxHVal;
    }
};

/*
Question Link: https://leetcode.com/problems/h-index-ii/
Author: M.R.Naganathan
*/
