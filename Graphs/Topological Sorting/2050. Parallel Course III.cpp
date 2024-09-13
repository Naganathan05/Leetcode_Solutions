/*----------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-------------------------*/

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> timeRequired(n + 1, -1e9);
        vector<vector<int>> adjList(n + 1);
        vector<int> inDegree(n + 1, 0);
        for(auto const& relation : relations){
            adjList[relation[0]].push_back(relation[1]);
            inDegree[relation[1]] += 1;
        }

        queue<int> fifo;
        for(int i = 1; i <= n; i++){
            if(inDegree[i] == 0){
                fifo.push(i);
                timeRequired[i] = time[i - 1];
            }
        }

        int maxTime = 0;
        while(!fifo.empty()){
            int currCourse = fifo.front();
            fifo.pop();

            maxTime = max(maxTime, timeRequired[currCourse]);

            for(int neighbour : adjList[currCourse]){
                inDegree[neighbour] -= 1;
                timeRequired[neighbour] = max(timeRequired[neighbour], (timeRequired[currCourse] + time[neighbour - 1]));
                if(inDegree[neighbour] == 0) fifo.push(neighbour);
            }
        }
        return maxTime;
    }
};

/*
Question Link: https://leetcode.com/problems/parallel-courses-iii/
Author: M.R.Naganathan
*/
