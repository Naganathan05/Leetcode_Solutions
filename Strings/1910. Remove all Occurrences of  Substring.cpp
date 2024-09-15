/*-----------------------------------------------
  Time Complexity: O(n) 
  Space Complexity: O(1)
-------------------------------------------------*/

class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        for(char c : s) {
            st.push(c);
            if(st.size() >= part.length() && st.top() == part.back()) {
                string temp = "";
                for(int i = 0; i < part.length(); i++) {
                    temp += st.top();
                    st.pop();
                }
                reverse(temp.begin(), temp.end());
                if(temp != part) {
                    for(char c : temp) {
                        st.push(c);
                    }
                }
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
Author: M.R.Naganathan
*/
