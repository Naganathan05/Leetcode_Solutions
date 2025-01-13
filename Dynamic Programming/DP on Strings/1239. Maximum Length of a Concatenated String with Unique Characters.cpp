/*------------------------------
  Time Complexity: O(n * 2^26)
  Space Complexity: O(n * 2^26)
--------------------------------*/

class Solution {
public:
    int concatString(vector<string> &arr, int i, int bitMask, unordered_map<int, unordered_map<int, int>> &dp) {
        if (i == arr.size()) return 0;
        if (dp[i].count(bitMask)) return dp[i][bitMask];

        string currString = arr[i];
        bool pickPossible = true;
        int newBitMask = bitMask;

        for (char c : currString) {
            int currChar = c - 'a';
            if (newBitMask & (1 << currChar)) {
                pickPossible = false;
                break;
            }
            newBitMask |= (1 << currChar);
        }

        int pick = 0, noPick = 0;
        if (pickPossible) pick = currString.length() + concatString(arr, i + 1, newBitMask, dp);
        noPick = concatString(arr, i + 1, bitMask, dp);

        return dp[i][bitMask] = max(pick, noPick);
    }

    int maxLength(vector<string>& arr) {
        unordered_map<int, unordered_map<int, int>> dp;
        return concatString(arr, 0, 0, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
Author: M.R.Naganathan
*/
