/*--------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------------------------*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        int cnt = 0;

        for(int i = 0; i <= nums.size() - 1; i++){
            freq[nums[i]]++;
        }

        for(auto i: freq){
            if(i.second == 1){
                return -1;
            }
            cnt += i.second/3;
            if(i.second % 3){
                cnt++;
            }
        }
        return cnt;
    }
};


/*---------------------------------------------------
Approach - 2
Time Complexity: O(nlogn)
Space Complexity: O(1)
Note: Referred Solution for this approach
-----------------------------------------------------*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, cnt = 0;

        while(i <= nums.size() - 1){
            j = i;
            while(j <= nums.size() - 1 && nums[i] == nums[j]){
                j++;
            }
            int size = j - i;
            if(size == 1){
                return -1;
            }
            cnt += size/3;
            if(size % 3){
                cnt += 1;
            }
            i = j;
        }
        return cnt;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/?envType=daily-question&envId=2024-01-04
Author: M.R.Naganathan
*/
