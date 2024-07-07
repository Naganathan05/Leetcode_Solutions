/*------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------------*/

class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans = "";
        for(int i = 0; i <= s.length() - 1; i++){
            ans  += s[(i + k) % s.length()];
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-encrypted-string/
Author: M.R.Naganathan
*/
