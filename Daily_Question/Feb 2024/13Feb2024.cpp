/*----------------------------------------------
  Time Complexity: O(n * m)
  Space Complexity: O(1)
------------------------------------------------*/

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string i : words){
            int f = 1;
            for(int j = 0; j <= i.length() - 1; j++){
                if(i[j] != i[i.length() - j - 1]){
                    f = 0;
                    break;
                }
            }
            if(f){
                return i;
            }
        }
        return "";
    }
};

/*
Question Link: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/?envType=daily-question&envId=2024-02-13
Author: M.R.Naganathan
*/
