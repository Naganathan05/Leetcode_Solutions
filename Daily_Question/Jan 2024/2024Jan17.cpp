/*---------------------------------------------------------------------------------------------
  Time Complexity: O(n + m*m) =>  n:Size of the array, m:Number of unique elements in the array
  Space Complexity: O(m)
-----------------------------------------------------------------------------------------------*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>freq;
        for(int i = 0; i <= arr.size() - 1; i++){
            freq[arr[i]]++;
        }
        for(auto i : freq){
            for(auto j : freq){
                if(i.second == j.second && i.first != j.first){
                    return 0;
                }
            }
        }
        return 1;
    }
};

/*
Question Link: https://leetcode.com/problems/unique-number-of-occurrences/?envType=daily-question&envId=2024-01-17
Author: M.R.Naganathan
*/
