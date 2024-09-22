/*----------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-------------------------*/

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        long long validCount = 0;
        int n = word1.size();
        int m = word2.size();

        unordered_map<char, int> freq2, windowFreq;
        for (char c : word2) freq2[c] += 1;

        int left = 0;
        int matched = 0;

        for (int right = 0; right < n; right++) {
            char rightChar = word1[right];
            if (freq2.count(rightChar)) {
                windowFreq[rightChar] += 1;
                if (windowFreq[rightChar] == freq2[rightChar]) matched += 1;
            }

            while (matched == freq2.size()) {
                validCount += (n - right);
                char leftChar = word1[left];
                if (freq2.count(leftChar)) {
                    if (windowFreq[leftChar] == freq2[leftChar]) matched -= 1;
                    windowFreq[leftChar] -= 1;
                }
                left += 1;
            }
        }
        return validCount;
    }
};

/*
Question Link: https://leetcode.com/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/
Author: M.R.Naganathan
*/
