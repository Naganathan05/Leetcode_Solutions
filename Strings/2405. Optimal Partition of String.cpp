/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-------------------------------------------------*/

class Solution {
public:
    int partitionString(string s) {
        s += " ";
        int i = 0, j = 0, ans = 0, flag = 0;
        unordered_map<char, int> freq;
        while(j <= s.length() - 1 && i <= j){
            if(flag == 0){
                freq[s[j]] += 1;
                j += 1;
            }
            else{
                ans += 1;
                freq.clear();
                j -= 1;
            }

            flag = 0;
            if(freq[s[j - 1]] >= 2) flag = 1;

            if(j == s.length() - 1 && !flag) ans += 1;
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/optimal-partition-of-string/description/
Author: M.R.Naganathan
*/
