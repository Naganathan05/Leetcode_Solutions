/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost = 0;
        stack<pair<char, int>> filo;
        for(int i = 0; i <= neededTime.size() - 1; i++) filo.push({colors[i], neededTime[i]});

        while(filo.size() >= 2){
            auto [firstBalloon, firstCost] = filo.top();
            filo.pop();
            auto [secondBalloon, secondCost] = filo.top();
            filo.pop();

            if(firstBalloon == secondBalloon){
                if(firstCost < secondCost){
                    filo.push({secondBalloon, secondCost});
                    totalCost += firstCost;
                }
                else{
                    filo.push({firstBalloon, firstCost});
                    totalCost += secondCost;
                }
            }
            else filo.push({secondBalloon, secondCost});
        }
        return totalCost;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
Author: M.R.Naganathan
*/
