/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    string decodeString(string s) {
        stack<string> stringStack;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ']') {
                stringStack.push(string(1, s[i]));
                continue;
            }

            string decodedString = "", currString = "";
            while(stringStack.top() != "[") {
                currString = stringStack.top() + currString;
                stringStack.pop();
            }
            stringStack.pop();

            string countStr = "";
            while(!stringStack.empty() && isdigit(stringStack.top()[0])) {
                countStr = stringStack.top() + countStr;
                stringStack.pop();
            }

            int count = stoi(countStr);
            for(int j = 0; j < count; j++) decodedString += currString;
            stringStack.push(decodedString);
        }

        string decodedString = "";
        while(!stringStack.empty()) {
            decodedString = stringStack.top() + decodedString;
            stringStack.pop();
        }
        return decodedString;
    }
};

/*
Question Link: https://leetcode.com/problems/decode-string/
Author: M.R.Naganathan
*/
