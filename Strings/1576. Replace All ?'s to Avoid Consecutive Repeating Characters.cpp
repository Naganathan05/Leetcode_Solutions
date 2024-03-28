/*-------------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
---------------------------------------------------*/

class Solution {
public:
    string modifyString(string s) {
        for(int i = 0; i <= s.length() - 1; i++){
            if(s[i] == '?'){
                if(i == 0){
                    for(int j = 97; j <= 122; j++){
                        s[i] = (char)j;
                        if(i + 1 < s.length()){
                            if(s[i] != s[i + 1]) break;
                        }
                        else{
                            return s.substr(0, s.length());
                        }
                    }
                }
                else if(i == s.length() - 1){
                    for(int j = 97; j <= 122; j++){
                        s[i] = (char)j;
                        if(s[i] != s[i - 1]) break;
                    }
                }
                else{
                    for(int j = 97; j <= 122; j++){
                        s[i] = (char)j;
                        if(s[i] != s[i - 1] && s[i] != s[i + 1]) break;
                    }
                }
            }
        }
        return s;
    }
};

/*
Question Link: https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
Author: M.R.Naganathan
*/
