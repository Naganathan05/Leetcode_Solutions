/*--------------------------------------------------------
  Time Complexity: O(n * 2^m)
  Space Complexity: O(n) + O(m) => Recursive Stack Space
----------------------------------------------------------*/

class Solution {
public:
    void Backtrack(vector<vector<int>> &requests, int i, int requestsCount, vector<int> &buildingStatus, int &maxRequests) {
        if(i == requests.size()) {
            for(int i : buildingStatus) {
                if(i) return;
            }
            maxRequests = max(maxRequests, requestsCount);
            return;
        }

        int remainingRequests = requests.size() - i;
        if(maxRequests > (requestsCount + remainingRequests)) return;

        buildingStatus[requests[i][0]] -= 1;
        buildingStatus[requests[i][1]] += 1;
        Backtrack(requests, i + 1, requestsCount + 1, buildingStatus, maxRequests);
        buildingStatus[requests[i][0]] += 1;
        buildingStatus[requests[i][1]] -= 1;

        Backtrack(requests, i + 1, requestsCount, buildingStatus, maxRequests);
        return;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> buildingStatus(n, 0);
        int maxRequests = 0;
        Backtrack(requests, 0, 0, buildingStatus, maxRequests);
        return maxRequests;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
Author: M.R.Naganathan
*/
