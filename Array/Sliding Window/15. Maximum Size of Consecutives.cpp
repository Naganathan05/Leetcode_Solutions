/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------*/

class Solution {
  public:
    int maximiseSubset(vector<long> arr, int k) {
        int usedPointsCount = 0, i = 0;
        int maxLen = k + 1;
        if(arr.size() == 1) return maxLen;
        for(int j = 1; j < arr.size(); j++){
            usedPointsCount += (arr[j] - arr[j - 1] - 1);
            while(usedPointsCount > k){
                usedPointsCount -= (arr[i + 1] - arr[i] - 1);
                i += 1;
            }
            int currSeqLen = (arr[j] - arr[i] + 1);
            maxLen = max(maxLen, currSeqLen + (k - usedPointsCount));
        }
        return maxLen;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/maximum-size-of-consecutives3154/1
Author: M.R.Naganathan
*/
