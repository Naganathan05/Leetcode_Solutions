/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), 
            [&](const vector<int> &a, const vector<int> &b) {
                return a[1] < b[1];
            }
        );

        priority_queue<int> maxHeap;
        int currTimer = 0;
        for(int i = 0; i < courses.size(); i++) {
            currTimer += courses[i][0];
            maxHeap.push(courses[i][0]);
            if(currTimer > courses[i][1]) {
                currTimer -= maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};

/*
Question Link: https://leetcode.com/problems/course-schedule-iii/
Author: M.R.Naganathan
*/
