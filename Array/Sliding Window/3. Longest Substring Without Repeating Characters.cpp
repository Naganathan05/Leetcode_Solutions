/*----------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
------------------------------------*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        unordered_map<char, int> freq;
        int i = 0, j = 0, max_len = 0;
        for(int j = 0; j <= s.length() - 1; j++){ 
            freq[s[j]] += 1;
            while(freq[s[j]] > 1){
                freq[s[i]] -= 1;
                i += 1;
            }
            max_len = max(max_len, (j - i + 1));
        }
        return max_len;
    }
};

/*
Question Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
Author: M.R.Naganathan
*/
