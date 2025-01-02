/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

func isVowel(ch rune) bool {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

func isSpecial(word string) bool {
    return isVowel(rune(word[0])) && isVowel(rune(word[len(word)-1]));
}

func vowelStrings(words []string, queries [][]int) []int {

    prefixSum := make([]int, len(words) + 1);
    prefixSum[0] = 0;
    for i, word := range words {
        prefixSum[i + 1] = prefixSum[i];
        if isSpecial(word) {
            prefixSum[i + 1] += 1;
        }
    }

    ans := make([]int, len(queries));
    for i, query := range queries {
        startPoint := query[0];
        endPoint := query[1] + 1;
        ans[i] = prefixSum[endPoint] - prefixSum[startPoint];
    }
    return ans;
}

/*
Question Link: https://leetcode.com/problems/count-vowel-strings-in-ranges/
Author: M.R.Naganathan
*/
