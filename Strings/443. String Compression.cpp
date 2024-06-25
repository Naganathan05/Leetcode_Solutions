/*-----------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------------------*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int k = 0;

        for (int i = 0; i < n; i++) {
            int cnt = 1;
            while (i + 1 < n && chars[i] == chars[i + 1]) {
                cnt++;
                i++;
            }
            
            chars[k++] = chars[i];
            
            if (cnt > 1) {
                string cntStr = to_string(cnt);
                for (char c : cntStr) {
                    chars[k++] = c;
                }
            }
        }
        return k;
    }
};


/*
Question Link: https://leetcode.com/problems/string-compression/
Author: M.R.Naganathan
*/
