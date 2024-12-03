/*--------------------------
  Time Complexity: O(2^n)
  Space Complexity: O(2^n)
-----------------------------*/

class Solution {
public:
    void Backtrack(string &tiles, vector<bool> &visited, string &currString, unordered_set<string> &ans){
        for(int i = 0; i <= tiles.length() - 1; i++){
            if(visited[i] == false){
                currString += tiles[i];
                visited[i] = true;
                if(ans.find(currString) == ans.end()) ans.insert(currString);
                Backtrack(tiles, visited, currString, ans);
                visited[i] = false;
                currString.pop_back();
            }
        }
        return;
    }

    int numTilePossibilities(string tiles) {
        vector<bool> visited(tiles.length(), false);
        string currString = "";
        unordered_set<string> ans;
        Backtrack(tiles, visited, currString, ans);
        return ans.size();
    }
};

/*
Question Link; https://leetcode.com/problems/letter-tile-possibilities/
Author: M.R.Naganathan
*/
