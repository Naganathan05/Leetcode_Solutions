/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
------------------------------------------------*/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        while(i <= nums1.size() - 1 && j <= nums2.size() - 1){
            if(nums1[i] > nums2[j]) j += 1;
            else if(nums1[i] < nums2[j]) i += 1;
            else return nums1[i];
        }
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09
Author: M.R.Naganathan
*/
