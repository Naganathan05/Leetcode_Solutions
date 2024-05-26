/*----------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
------------------------------------------*/

class Solution {
public:
    string compressedString(string word) {
        int i = 0;
        string comp = "";
        while(i <= word.length() - 1){
            int cnt = 1;
            int j = i;
            while(j <= word.length() - 2 && word[j] == word[j + 1] && cnt != 9){
                cnt += 1;
                j += 1;
            }
            i = j + 1;
            comp += (to_string(cnt) + word[j]);
        }
        return comp;
    }
};

/*
Question Link: https://leetcode.com/problems/string-compression-iii/
Author: M.R.Naganathan
*/
