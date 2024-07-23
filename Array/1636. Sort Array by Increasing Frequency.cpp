/*--------------------------------
  Time Complexit: O(nlogn)
  Space Complexity: O(n)
----------------------------------*/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i : nums) freq[i] += 1;

        sort(nums.begin(), nums.end(), [&freq](int a, int b){
            if(freq[a] == freq[b]) return a > b;
            return freq[a] < freq[b];
        });
        return nums;
    }
};

/*
Question Link: https://leetcode.com/problems/sort-array-by-increasing-frequency/
Author: M.R.Naganathan
*/
