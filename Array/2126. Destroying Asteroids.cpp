/*-----------------------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
-------------------------------------------------*/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m = mass;
        sort(asteroids.begin(), asteroids.end());
        for(int i = 0; i <= asteroids.size() - 1; i++){
            if(m < asteroids[i]) return false;
            m += asteroids[i];
        }
        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/destroying-asteroids/description/
Author: M.R.Naganathan
*/
