/*---------------------------------------------
  Time Complexity: O(1)
  Space Complexity: O(1)
-----------------------------------------------*/

class Solution {
public:
    int minimumSum(int num) {
        vector<int> arr;
        while(num > 0){
            arr.push_back(num % 10);
            num /= 10;
        }
        sort(arr.begin(), arr.end());
        return (arr[0]*10 + arr[2]) + (arr[1]*10 + arr[3]);
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
Author: M.R.Naganathan
*/
