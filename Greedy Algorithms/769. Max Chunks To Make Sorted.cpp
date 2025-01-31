/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        unordered_map<int, int> seenElements;
        int target = 0, numChunks = 0;
        int currMax = -1;
        for(int i = 0; i <= arr.size() - 1; i++){
            seenElements[arr[i]] += 1;
            currMax = max(currMax, arr[i]);
            if(arr[i] == target){
                while(target <= currMax && seenElements.find(target) != seenElements.end()) target += 1;
                numChunks += (target == currMax + 1);
            }
        }
        return numChunks;
    }
};

/*
Question Link: https://leetcode.com/problems/max-chunks-to-make-sorted/
Author: M.R.Naganathan
*/
