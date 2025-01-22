/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------*/

func longestSemiRepetitiveSubstring(s string) int {
    maxLen, i, numRepetitions := 1, 0, 0
    for j := 1; j < len(s); j++ {
        if s[j] == s[j - 1] {
            numRepetitions += 1;
        }
        for numRepetitions > 1 {
            if s[i] == s[i + 1] {
                numRepetitions -= 1;
            }
            i += 1;
        }
        maxLen = max(maxLen, (j - i + 1));
    }
    return maxLen
}

/*
Question Link: https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/
Author: M.R.Naganathan
*/
