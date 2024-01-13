/*---------------------------------------------
  Time Complexity: O(n)  =>  n:Length of the string
  Space Complexity: O(1)
----------------------------------------------*/

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> freq_s, freq_t;        
        for(char c : s){
            freq_s[c]++;
        }
        for(char c : t){
            freq_t[c]++;
        }
        int minimum_moves = 0;
        for(auto key : "abcdefghijklmnopqrstuvwxyz"){
            minimum_moves += abs(freq_s[key] - freq_t[key]);
        }
        return minimum_moves/2;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/?envType=daily-question&envId=2024-01-13
Author: M.R.Naganathan
*/
