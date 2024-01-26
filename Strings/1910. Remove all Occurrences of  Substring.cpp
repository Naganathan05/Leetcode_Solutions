/*-----------------------------------------------
  Time Complexity: O(n) 
  Space Complexity: O(1)
-------------------------------------------------*/

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int f = 1;
        while(f){
            f = 0;
            for(int i = 0; i <= s.size() - 1; i++){
                int j = 0;
                while(j <= part.size() - 1 && part[j] == s[i + j] && (j + i) <= s.size() - 1){
                    j += 1;
                }
                if(j == part.size()){
                    f = 1;
                    s = s.substr(0, i) + s.substr(i + j, s.size() - j);
                }
            }
        }
        return s;
    }
};

/*
Question Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
Author: M.R.Naganathan
*/
