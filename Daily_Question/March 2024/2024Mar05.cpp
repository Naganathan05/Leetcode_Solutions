/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
------------------------------------------------*/

class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.length() - 1;
        char prev = ' ';
        while (i < j){
            if(s[i] == s[j]){
                prev = s[i];
                i += 1;
                j -= 1;
            }
            else if(s[i] == prev){
                i += 1;
            }
            else if(s[j] == prev){
                j -= 1;
            }
            else if(s[i] != s[j]){
                break;
            }
        }
        if(i == j && s[i] == prev) return 0;
        return j - i + 1;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05
Author: M.R.Naganathan
*/
