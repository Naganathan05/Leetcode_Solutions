/*------------------------
n = Number of Flights
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> lineSweep(n + 2, 0);
        for(auto &booking : bookings) {
            lineSweep[booking[0]] += booking[2];
            lineSweep[booking[1] + 1] -= booking[2];
        }

        vector<int> answer(n, 0);
        for(int i = 1; i <= n; i++) {
            if(i == 1) answer[i - 1] = lineSweep[i];
            else answer[i - 1] = lineSweep[i] + answer[i - 2];
        }
        return answer;
    }
};

/*
Question Link: https://leetcode.com/problems/corporate-flight-bookings/
Author: M.R.Naganathan
*/
