/*--------------------------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
-----------------------------------------------*/

class Solution {
public:
    void palindrome(string s, int i, vector<string> &currPartition, vector<vector<string>> &ans){
        if(i == s.length()){
            int len = s.length();
            for(string str : currPartition) len -= (str.length());
            if(!len) ans.push_back(currPartition);
            return;
        }

        for(int j = i; j <= s.length() - 1; j++){
            if(checkPalindrome(s, i, j)){
                currPartition.push_back(s.substr(i, j - i + 1));
                palindrome(s, j + 1, currPartition, ans);
                currPartition.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> currPartition;
        palindrome(s, 0, currPartition, ans);
        return ans;
    }

    bool checkPalindrome(string &str, int i, int j){
        while(i < j){
            if(str[i] != str[j]) return false;
            i += 1;
            j -= 1;
        }
        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/palindrome-partitioning/
Author: M.R.Naganathan
*/
