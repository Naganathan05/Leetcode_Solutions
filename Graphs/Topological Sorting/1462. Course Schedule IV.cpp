/*---------------------------
  Time Complexity: O(V * E)
  Space Complexity: O(V + E)
-----------------------------*/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> isPrerequisite(queries.size(), false);
        vector<vector<bool>> Reachability(numCourses, vector<bool> (numCourses, false));
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
            inDegree[prerequisites[i][1]]++;
        }

        queue<int> fifo;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) fifo.push(i);
        }

        while (!fifo.empty()) {
            int currCourse = fifo.front();
            fifo.pop();

            for (auto neighbor : adjList[currCourse]) {
                Reachability[currCourse][neighbor] = true;
                inDegree[neighbor] -= 1;
                if (inDegree[neighbor] == 0) fifo.push(neighbor);
                for (int i = 0; i < numCourses; i++) {
                    if (Reachability[i][currCourse]) Reachability[i][neighbor] = true;
                }
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            isPrerequisite[i] = Reachability[queries[i][0]][queries[i][1]];
        }
        return isPrerequisite;
    }
};

/*
Question Link: https://leetcode.com/problems/course-schedule-iv/
Author: M.R.Naganathan
*/
