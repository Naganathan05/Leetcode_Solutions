/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
------------------------------------------------*/

class Solution {
public:
    int pivotInteger(int n) {
        int leftSum = 0;
        int rightSum = 0;
        
        for(int i = 1; i <= n; i++) {
            leftSum = i * (i + 1) / 2; 
            rightSum = n * (n + 1) / 2 - i * (i - 1) / 2;  
            if(leftSum == rightSum)
                return i; 
        }
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-pivot-integer/?envType=daily-question&envId=2024-03-13
Author: M.R.Naganathan
*/
