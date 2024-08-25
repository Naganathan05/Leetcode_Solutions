/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------*/

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int numBoxes = status.size(), maxCandies = 0;
        vector<bool> Openable(numBoxes, false);
        vector<bool> alreadyOpened(numBoxes, false);
        queue<int> fifo;
        for(int box : initialBoxes){
            if(status[box]){
                fifo.push(box);
                alreadyOpened[box] = true;
            }
            else Openable[box] = true;
        }

        while(!fifo.empty()){
            int currBox = fifo.front();
            fifo.pop();

            maxCandies += (candies[currBox]);
            for(int newKey : keys[currBox]){
                if(!alreadyOpened[newKey]){
                    status[newKey] = 1;
                    if(Openable[newKey]){ 
                        fifo.push(newKey);
                        alreadyOpened[newKey] = true;
                    }
                }
            }

            for(int newBox : containedBoxes[currBox]){
                if(status[newBox] && !alreadyOpened[newBox]){
                    fifo.push(newBox);
                    alreadyOpened[newBox] = true;
                }
                else if(!status[newBox]) Openable[newBox] = true;
            }
        }
        return maxCandies;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/
Author: M.R.Naganathan
*/
