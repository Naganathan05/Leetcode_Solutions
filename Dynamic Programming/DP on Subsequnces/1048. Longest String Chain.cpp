/*--------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    bool isSubsequence(string &a, string &b){
        int i = 0, j = 0;
        while(i <= a.size() - 1 && j <= b.size() - 1){
            i += (a[i] == b[j]);
            j += 1;
        }
        return i == a.size();
    }

    static bool comparator(string &a, string &b){
        return a.size() < b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comparator);
        vector<int> curr(words.size() + 1,0);
        vector<int> next(words.size()+1,0);
        for(int i = words.size() - 1; i >= 0; i--){ 
            for(int j = words.size()-1; j >= -1; j--){
                if(j == -1){
                    curr[j + 1] = max(next[j + 1], 1 + next[i + 1]);
                    continue;
                }
                int maxi = 0;
                if(words[j].size() == words[i].size() - 1 && isSubsequence(words[j], words[i])) curr[j+1] = 1 + next[i+1];
                curr[j + 1] = max(curr[j + 1], next[j + 1]);   
            }
            next = curr;
        }
        return curr[0];
    }
};

/*
Question Link: https://leetcode.com/problems/longest-string-chain/
Author: M.R.Naganathan
*/
