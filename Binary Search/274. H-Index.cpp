/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
------------------------------*/

class Solution {
public:
    bool validateHIndex(vector<int> &citations, int hValue){
        int numCitations = 0;
        for(int i : citations) numCitations += (i >= hValue);
        return numCitations >= hValue;
    }

    int hIndex(vector<int>& citations) {
        int low = 0, high = citations.size();
        int maxHValue = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(validateHIndex(citations, mid)){
                maxHValue = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return maxHValue;
    }
};

/*
Question Link: https://leetcode.com/problems/h-index/
Author: M.R.Naganathan
*/
