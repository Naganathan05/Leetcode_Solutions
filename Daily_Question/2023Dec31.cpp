/*----------------------------------------------
  Time Complexity: O(n^2)
  Space Complexity: O(1)
------------------------------------------------*/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int cnt = -1;

        for(int i = 0; i <= s.length() - 1; i++){
            for(int j = i + 1; j <= s.length() - 1; j++){
                cnt = (s[i] == s[j]) ? max(cnt, j - i - 1) : cnt = cnt;
            }
        }
        return cnt;
    }
};

/*
Question Link: https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/?envType=daily-question&envId=2023-12-31
Author: M.R.Naganathan
*/
