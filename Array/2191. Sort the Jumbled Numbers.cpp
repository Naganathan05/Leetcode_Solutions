/*----------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-------------------------------*/

class Solution {
public:
    unordered_map<int, int> mappedNumbers;
    static bool comparator(int a, int b, unordered_map<int, int>& mappedNumbers) {
        return mappedNumbers[a] < mappedNumbers[b];
    }

    int mapInteger(vector<int>& mapping, int num) {
        if(num == 0) return mapping[0];

        int mappedNumber = 0;
        vector<int> digits;
        while(num > 0) {
            digits.push_back(mapping[num % 10]);
            num /= 10;
        }

        for(int i = digits.size() - 1; i >= 0; i--) {
            mappedNumber = mappedNumber * 10 + digits[i];
        }
        return mappedNumber;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        for(int i : nums) {
            mappedNumbers[i] = mapInteger(mapping, i);
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return comparator(a, b, mappedNumbers);
        });
        return nums;
    }
};

/*
Question Link: https://leetcode.com/problems/sort-the-jumbled-numbers/description/
Author: M.R.Naganathan
*/
