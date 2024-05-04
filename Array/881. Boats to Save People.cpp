/*-----------------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
--------------------------------------------*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int st = 0, en = people.size() - 1, cnt = 0;
        while(st <= en){
            if(people[st] + people[en] <= limit){
                st += 1;
            }
            cnt += 1;
            en -= 1;
        }
        return cnt;
    }
};

/*
Question Link: https://leetcode.com/problems/boats-to-save-people/
Author: M.R.Naganathan
*/
