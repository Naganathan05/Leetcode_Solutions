/*---------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mapping;
        for(int i = 0; i <= arr.size() - 1; i++) mapping[arr[i]].push_back(i);
        
        queue<int> fifo;
        fifo.push(0);
        vector<bool> visited(arr.size(), false);
        visited[0] = true;
        int steps = 0;
        while(!fifo.empty()){
            int size = fifo.size();
            for(int i = 0; i < size; i++){
                int ind = fifo.front();
                fifo.pop();

                if(ind == arr.size() - 1) return steps;
                if(ind + 1 <= arr.size() && !visited[ind + 1]){
                    visited[ind + 1] = true;
                    fifo.push(ind + 1);
                }
                if(ind - 1 >= 0 && !visited[ind - 1]){
                    visited[ind - 1] = true;
                    fifo.push(ind - 1);
                }

                for(int itr : mapping[arr[ind]]){
                    if(itr != ind && !visited[itr]){
                        fifo.push(itr);
                        visited[itr] = true;
                    }
                }
                mapping[arr[ind]].clear();
            }
            steps += 1;
        }
        return 0;
    }
};

/*
Question Link: https://leetcode.com/problems/jump-game-iv/
Author: M.R.Naganathan
*/
