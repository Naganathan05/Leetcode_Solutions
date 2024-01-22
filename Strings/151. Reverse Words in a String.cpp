/*--------------------------------------------------
  Time Complexity: O(n)  =>  n:Length of the String
  Space Complexity: O(n)
----------------------------------------------------*/

class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        if(s.length() == 0 || (s.length() == 1 && s[0] != ' ')){
            return s;
        }
        else if(s.length() == 1 && s[0] == ' '){
            return "";
        }
        for(int i = s.length() - 1; i >= 0; i--){
            int j = i;
            while(j >= 0 && s[j] != ' '){
                j--;
            }
            str += s.substr(j + 1, i - j) + " ";
            i = j;
        }
        int i = 0;
        while(i <= str.length() - 1 && str[i] == ' '){
            i += 1;
        }
        str = str.substr(i, str.length() - i);
        i = str.length() - 1;
        while(i >= 0 && str[i] == ' '){
            str = str.substr(0, str.length() - (str.length() - i));
            i -= 1;
        }
        for(int i = 0; i <= str.length() - 2; i++){
            if(str[i] == str[i + 1] && str[i] == ' '){
                str = str.substr(0, i + 1) + str.substr(i + 2, str.length() - i - 1);
                 i -= 1;
            }
        }
        return str;
    }
};

/*
Question Link: https://leetcode.com/problems/reverse-words-in-a-string/
Author: M.R.Naganathan
*/
