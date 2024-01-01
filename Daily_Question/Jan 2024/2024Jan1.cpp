/*---------------------------------------------
  Time Complexity: O(nlogn + mlogm) 
  Space Complexity: O(1)
  m: size of the child's greedness array
  n: size of the chocolates array
-----------------------------------------------*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0, j = 0, ans = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        if(s.size() <= 0 || g.size() <= 0){
            return 0;
        }
        
        while(i <= g.size() - 1 && j <= s.size() - 1){
            if(g[i] <= s[j]){
                ans++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/assign-cookies/?envType=daily-question&envId=2024-01-01
Author: M.R.Naganathan
*/
