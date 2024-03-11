/*-----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-------------------------------------------------*/

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> freq;
        string ans = "";
        for(char i : s) freq[i] += 1;
        for(char i : order){
            if(freq[i] > 0){
                while(freq[i]){
                    ans += i;
                    freq[i] -= 1;
                }
            }
        }
        for(auto i : freq){
            if(i.second > 0){
                while(i.second){
                    ans += i.first;
                    i.second -= 1;
                }
            }
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/custom-sort-string/?envType=daily-question&envId=2024-03-11
Author: M.R.Naganathan
*/
