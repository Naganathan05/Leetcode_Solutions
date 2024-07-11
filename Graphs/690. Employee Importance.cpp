/*-----------------------------------
Method: Breadth First Search
  Time Complexity: O(V + 2E)
  Space Complexity: O(V + E)
-------------------------------------*/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int numEmployees = employees.size();
        unordered_map<int, int> Importance;
        unordered_map<int, vector<int>> adjList;
        for(int i = 0; i < numEmployees; i++){
            Importance[employees[i] -> id] = employees[i] -> importance;
            for(int subId : employees[i] -> subordinates) adjList[employees[i] -> id].push_back(subId);
        }

        queue<int> fifo;
        fifo.push(id);
        int totalImportance = 0;
        while(!fifo.empty()){
            int currId = fifo.front();
            fifo.pop();
            totalImportance += (Importance[currId]);
            for(int i : adjList[currId]) fifo.push(i);
        }
        return totalImportance;
    }
};

/*
Question Link: https://leetcode.com/problems/employee-importance/
Author: M.R.Naganathan
*/
