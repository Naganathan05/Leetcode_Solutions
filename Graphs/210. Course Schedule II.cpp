/*----------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0){
            vector<int> topoSort;
            for(int i = 0; i < numCourses; i++) topoSort.push_back(i);
            return topoSort;
        }

        vector<vector<int>> adjList(numCourses);
        for(int i = 0; i <= prerequisites.size() - 1; i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> topoOrder, inDegrees(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            for(int j : adjList[i]) inDegrees[j] += 1;
        }

        queue<int> fifo;
        for(int i = 0; i < numCourses; i++){
            if(inDegrees[i] == 0) fifo.push(i);
        }

        while(!fifo.empty()){
            int course = fifo.front();
            fifo.pop();
            topoOrder.push_back(course);

            for(int it : adjList[course]){
                inDegrees[it] -= 1;
                if(inDegrees[it] == 0) fifo.push(it);
            }
        }
        
        if(topoOrder.size() == numCourses) return topoOrder;
        return {};
    }
};

/*
Question Link: https://leetcode.com/problems/course-schedule-ii/
Author: M.R.Naganathan
*/
