/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-----------------------------------------------*/

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str;
        int j = 0;
        for(int i = 0; i <= s.size() - 1; i++){
            if(j != spaces.size() && i == spaces[j]){
                str += " ";
                j += 1;
            }
            str += s[i];
        }
        return str;
    }
};

/*
Question Link: https://leetcode.com/problems/adding-spaces-to-a-string/description/
Author: M.R.Naganathan
*/
