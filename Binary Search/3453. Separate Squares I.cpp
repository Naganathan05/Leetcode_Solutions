/*--------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
----------------------------*/

class Solution {
public:
    int checkEqualArea(vector<vector<int>> &squares, double splitLine) {
        double downArea = 0, upArea = 0;

        for (auto &square : squares) {
            double bottom = square[1];
            double top = bottom + square[2];
            double area = (double)square[2] * (double)square[2];

            if (top <= splitLine) downArea += area;
            else if (bottom >= splitLine) upArea += area;
            else {
                upArea += (top - splitLine) * square[2];
                downArea += (splitLine - bottom) * square[2];
            }
        }

        if (upArea - downArea < 1e-5) return 1;
        return (upArea > downArea) ? 0 : -1;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e9, high = -1e9;

        for (auto &square : squares) {
            low = min(low, (double)square[1]);  
            high = max(high, (double)(square[1] + square[2]));  
        }

        double ans = -1;
        while (high - low > 1e-5) {  
            double mid = low + (high - low) / 2;
            int decision = checkEqualArea(squares, mid);

            if (decision == 1) {
                ans = mid;
                high = mid;
            }
            else if (decision == 0) low = mid;  
            else  high = mid;  
        }
        return ans == -1 ? high : ans;
    }
};

/*
Question Link: https://leetcode.com/problems/separate-squares-i/
Author: M.R.Naganathan
*/
