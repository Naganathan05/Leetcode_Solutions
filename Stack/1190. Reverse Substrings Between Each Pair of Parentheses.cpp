/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> filo;
        for(int i = 0; i <= s.length() - 1; i++){
            if(s[i] != ')'){
                filo.push(s[i]);
                continue;
            }
            string revString = "";
            char currChar = filo.top();
            while(currChar != '('){
                revString += currChar;
                filo.pop();
                currChar = filo.top();
            }
            filo.pop();
            for(char c : revString) filo.push(c);
        }

        string reversedString = "";
        while(!filo.empty()){
            reversedString = filo.top() + reversedString;
            filo.pop();
        }
        return reversedString;
    }
};

/*
Question Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
Author: M.R.Naganathan
*/
