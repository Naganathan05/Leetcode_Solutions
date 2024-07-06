/*----------------------------------
  Time Complexity: O(3^n)
  Space Complexity: O(n * n)
------------------------------------*/

class Solution{
    public:
    void Move(vector<vector<int>> &m, int n, int i, int j, string &currString, vector<string> &ans){
        if(i < 0 || j < 0 || j >= n || i >= n || m[i][j] == 0) return;
        if(i == n - 1 && j == n - 1){
            ans.push_back(currString);
            return;
        }
        
        m[i][j] = 0;
        
        // Up
        currString.push_back('U');
        Move(m, n, i - 1, j, currString, ans);
        currString.pop_back();
        
        // Down
        currString.push_back('D');
        Move(m, n, i + 1, j, currString, ans);
        currString.pop_back();
        
        // Left
        currString.push_back('L');
        Move(m, n, i, j - 1, currString, ans);
        currString.pop_back();
        
        // Right
        currString.push_back('R');
        Move(m, n, i, j + 1, currString, ans);
        currString.pop_back();
        
        m[i][j] = 1;
        
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string currString;
        Move(m, n, 0, 0, currString, ans);
        return ans;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
Author: M.R.Naganathan
*/
