/*-------------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------------------------------*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        long count = 0, max = INT_MIN, j = 1;
        unordered_map<int, long> freq;
        for(int i = 0; i <= time.size() - 1; i++){
            freq[time[i]]++;
        }
        for(int i = 0; i <= time.size() - 1; i++){
            if(max < time[i]) max = time[i];
        }
        for(int i = 0; i <= time.size() - 1; i++){
            int x = INT_MIN;
            j = 1;
            while(x <= max){
                x = j*60 - time[i];
                if(freq[x] && x != time[i]){
                    count += freq[x];
                }
                else if(x == time[i] && freq[x]){
                    count += freq[time[i]] - 1;
                }
                j++;
            }
        }
        return count/2;
    }
};

/*
Question Link: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
Author: M.R.Naganathan
*/
