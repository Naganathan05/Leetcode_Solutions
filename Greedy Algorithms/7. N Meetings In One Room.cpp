/*-----------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
--------------------------------*/

class Solution
{
    public:
    int maxMeetings(int n, int start[], int end[])
    {
        vector<vector<int>> Task(n);
        for(int i = 0; i <= n - 1; i++){
            Task[i].push_back(end[i]);
            Task[i].push_back(start[i]);
        }
        sort(Task.begin(), Task.end());
        int lastEndTime = Task[0][0], maxTasks = 1;
        for(int i = 1; i <= n - 1; i++){
            if(Task[i][1] > lastEndTime){
                maxTasks += 1;
                lastEndTime = Task[i][0];
            }
        }
        return maxTasks;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
Author: M.R.Naganathan
*/
