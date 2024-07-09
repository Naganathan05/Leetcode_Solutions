/*---------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int lastOrderFinishTime = 0;
        int numCustomers = customers.size();
        double totalWaiting = 0.0;

        for (int i = 0; i < numCustomers; ++i) {
            int arrivalTime = customers[i][0];
            int orderTime = customers[i][1];

            if (lastOrderFinishTime > arrivalTime) {
                totalWaiting += (lastOrderFinishTime - arrivalTime) + orderTime;
                lastOrderFinishTime += orderTime;
            } else {
                totalWaiting += orderTime;
                lastOrderFinishTime = arrivalTime + orderTime;
            }
        }
        return totalWaiting / numCustomers;
    }
};

/*
Question Link: https://leetcode.com/problems/average-waiting-time/
Author: M.R.Naganathan
*/
