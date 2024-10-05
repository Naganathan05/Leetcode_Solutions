/*--------------------------
  Time Complexity: O(logn)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    int mySqrt(int x) {
        long long low = 1, high = x, sqrt = 0;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long squareValue = mid * mid;
            if(squareValue > x) high = mid - 1;
            else{
                sqrt = mid;
                low = mid + 1;
            }
        }
        return sqrt;
    }
};

/*
Question Link: https://leetcode.com/problems/sqrtx/
Author: M.R.Naganathan
*/
