/*--------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int maxLen = 0, i = 0, maxFreq = 0;
        for(int j = 0; j <= s.length() - 1; j++){
            freq[s[j]] += 1;
            maxFreq = max(maxFreq, freq[s[j]]);
            while(i < s.length() && ((j - i + 1) - maxFreq) > k){
                freq[s[i]] -= 1;
                i += 1;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};

/*
Question Link: https://leetcode.com/problems/longest-repeating-character-replacement/
Author: M.R.Naganathan
*/
