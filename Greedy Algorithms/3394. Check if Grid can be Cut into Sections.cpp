/*--------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    bool cutRectangle(int n, vector<pair<int, int>>& coords) {
        sort(coords.begin(), coords.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });

        int sections = 1;
        int lastEnd = coords[0].second;

        for (int i = 1; i < coords.size(); i++) {
            if (coords[i].first >= lastEnd) {
                sections += 1;
                lastEnd = coords[i].second;
            } 
            else lastEnd = max(lastEnd, coords[i].second);
        }
        return sections >= 3;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> xCoords, yCoords;

        for (const auto& rect : rectangles) {
            xCoords.push_back({rect[0], rect[2]});
            yCoords.push_back({rect[1], rect[3]});
        }
        return cutRectangle(n, xCoords) || cutRectangle(n, yCoords);
    }
};

/*
Question Link: https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/
Author: M.R.Naganathan
*/
