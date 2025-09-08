/*----------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string beautifulSubstring = "";
        int i = 0, numOnes = 0;
        for(int j = 0; j < s.length(); j++) {
            numOnes += (s[j] == '1');
            while(numOnes == k) {
                string currSubString = s.substr(i, (j - i + 1));
                if(beautifulSubstring.empty() || beautifulSubstring.length() > (j - i + 1)) {
                    beautifulSubstring = currSubString;
                }
                else if(beautifulSubstring.length() == (j - i + 1)) {
                    beautifulSubstring = min(beautifulSubstring, currSubString);
                }

                numOnes -= (s[i] == '1');
                i += 1;
            }
        }
        return beautifulSubstring;
    }
};

/*
Question Link: https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/
Author: M.R.Naganathan
*/
