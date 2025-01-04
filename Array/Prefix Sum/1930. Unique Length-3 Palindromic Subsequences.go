/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

func countPalindromicSubsequence(s string) int {
    n := len(s)
    firstOccurrence := make([]int, 26)
    lastOccurrence := make([]int, 26)
    for i := 0; i < 26; i++ {
        firstOccurrence[i] = -1
        lastOccurrence[i] = -1
    }

    for i := 0; i < n; i++ {
        index := int(s[i] - 'a')
        if firstOccurrence[index] == -1 {
            firstOccurrence[index] = i
        }
        lastOccurrence[index] = i
    }

    result := 0
    for ch := 0; ch < 26; ch++ {
        start := firstOccurrence[ch]
        end := lastOccurrence[ch]
        if start != -1 && end != -1 && start < end {
            middleSet := make(map[byte]bool)
            for i := start + 1; i < end; i++ {
                middleSet[s[i]] = true
            }
            result += len(middleSet)
        }
    }
    return result
}

/*
Question Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/
Author: M.R.Naganathan
*/
