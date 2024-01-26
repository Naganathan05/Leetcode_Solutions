/*----------------------------------------------
  Time Complexity: O(22 * n) ==> O(n)
  Space Complexity: O(1)
------------------------------------------------*/

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        map<int, int> freq;
        long cnt = 0;
        int maximum = INT_MIN;
        for(int i = 0; i <= deliciousness.size() - 1; i++){
            freq[deliciousness[i]]++;
            maximum = max(maximum, deliciousness[i]);
        }
        for(int i = 0; i <= deliciousness.size() - 1; i++){
            int base = 1;
            while(base - deliciousness[i] <= maximum){
                if(freq[base - deliciousness[i]] > 0){
                    if(base - deliciousness[i] == deliciousness[i]){
                        cnt += freq[base - deliciousness[i]] - 1;
                    }
                    else{
                        cnt += freq[base - deliciousness[i]];
                    }
                }
                base *= 2;
            }
        }
        return (cnt/2) % 1000000007;
    }
};

/*
Question Link: https://leetcode.com/problems/count-good-meals/
Author: M.R.Naganathan
*/
