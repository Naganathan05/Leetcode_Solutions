/*----------------------------------------
  Time Complexity: O(n * log(max - min))
  Space Complexity: O(1)
------------------------------------------*/

class Solution {
  public:
    bool validateMinDistance(vector<int> &stalls, int minDist, int &k) {
        int numCowsPlaced = 1, prevPlacedPos = stalls[0];
        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - prevPlacedPos < minDist) continue;
            prevPlacedPos = stalls[i];
            numCowsPlaced += 1;
        }
        return numCowsPlaced >= k;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls.back() - stalls[0];
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(validateMinDistance(stalls, mid, k)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};

/*
Question Link: http://geeksforgeeks.org/problems/aggressive-cows/1
Author: M.R.Naganathan
*/
