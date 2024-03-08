/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
------------------------------------------------*/

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map <int, int> freq;
        for(int i : nums){
            freq[i] += 1;
        }
        int max_freq = INT_MIN, cnt = 0;
        for(auto i : freq){
            if(i.second > max_freq) max_freq = i.second;
        }
        for(auto i : freq){
            if(i.second == max_freq) cnt += i.second;
        }
        return cnt;
    }
};

/*
Question Link: https://leetcode.com/problems/count-elements-with-maximum-frequency/?envType=daily-question&envId=2024-03-08
Author: M.R.Naganathan
*/
