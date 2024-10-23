/*--------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(), answers.end());
        int numRabbits = 0, i = 0;
        while(i <= answers.size() - 1){
            int maxGroupSize = answers[i];
            int j = i + 1;
            while(j < answers.size() && answers[i] == answers[j] && maxGroupSize > 0){
                j += 1;
                maxGroupSize -= 1;
            }
            numRabbits += (answers[i] + 1);
            i = j;
        }
        return numRabbits;
    }
};

/*
Question Link: https://leetcode.com/problems/rabbits-in-forest/
Author: M.R.Naganathan
*/
