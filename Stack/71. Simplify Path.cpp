/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string finalPath = "";

        for(int i = 0; i <= path.length() - 1; i++){
            if(path[i] == '/') continue;
            string currPath = "";
            while(i <= path.length() - 1 && path[i] != '/'){
                currPath += path[i];
                i += 1;
            }
            if(currPath == ".") continue;
            if(currPath == ".."){
                if(!st.empty()) st.pop();
            }
            else st.push(currPath);
        }

        while(!st.empty()){
            finalPath = ("/" + st.top()) + finalPath;
            st.pop();
        }
        if(finalPath.length()) return finalPath;
        return "/";
    }
};

/*
Question Link: https://leetcode.com/problems/simplify-path/
Author: M.R.Naganathan
*/
