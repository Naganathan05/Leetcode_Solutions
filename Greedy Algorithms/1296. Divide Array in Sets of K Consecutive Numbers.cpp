/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> sortedFreq;
        for(int i : nums) sortedFreq[i] += 1;

        while(sortedFreq.size()){
            int startingElement = sortedFreq.begin() -> first;
            for(int i = startingElement; i < (startingElement + k); i++){
                if(sortedFreq.find(i) == sortedFreq.end()) return false;
                sortedFreq[i] -= 1;
                if(sortedFreq[i] == 0) sortedFreq.erase(i);
            }
        }
        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
Author: M.R.Naganathan
*/
