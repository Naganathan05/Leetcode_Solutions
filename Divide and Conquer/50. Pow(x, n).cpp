/*-------------------------
  Time Complexity: O(logn)
  Space Complexity: O(1)
----------------------------*/

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1) return 1;
        if(x == 0) return 0;

        long long N = n;
        if(N < 0) {
            x = 1 / x;
            N = -N; 
        }

        double result = 1;
        while(N > 0) {
            if(N % 2 == 1) result *= x;
            x *= x;
            N /= 2;
        }
        return result;
    }
};

/*
Question Link: https://leetcode.com/problems/powx-n/
Author: M.R.Naganathan
*/
