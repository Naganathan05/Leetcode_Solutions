/*----------------------------------
  Time Complexity: O(2^n)
  Space Complexity: O(2^n) + O(n)
------------------------------------*/

class Solution {
public:
    void generate(int i, int n, string currString, vector<string> &ans, bool onePushed){
        if(i == 0){
            ans.push_back(currString);
            return;
        }

        if(i != n && !onePushed){
            currString += '1';
            generate(i - 1, n, currString, ans, true);
            currString.pop_back();
            return;
        }

        currString += '1';
        generate(i - 1, n, currString, ans, true);
        currString.pop_back();

        currString += '0';
        generate(i - 1, n, currString, ans, false);
        currString.pop_back();
        return;
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        string currString = "";
        generate(n, n, currString, ans, false);
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/
Author: M.R.Naganathan
*/
