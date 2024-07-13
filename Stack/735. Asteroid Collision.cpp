/*-----------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-------------------------------*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i : asteroids){
            if(st.empty() || i > 0) st.push(i);
            else{
                while(!st.empty() && st.top() > 0 && st.top() < abs(i)){
                    st.pop();
                }
                if (st.empty() || st.top() < 0) {
                    st.push(i);
                } else if (st.top() == abs(i)) {
                    st.pop();
                }
            }
        }
        vector<int> remainingAsteroids;
        while(!st.empty()){
            remainingAsteroids.push_back(st.top());
            st.pop();
        }
        reverse(remainingAsteroids.begin(), remainingAsteroids.end());
        return remainingAsteroids;
    }
};

/*
Question Link: https://leetcode.com/problems/asteroid-collision/
Author: M.R.Naganathan
*/
