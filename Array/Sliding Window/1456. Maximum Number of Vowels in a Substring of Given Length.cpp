/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------*/

class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int maxVowel = 0;
        for(int i = 0; i < k; i++) maxVowel += isVowel(s[i]);
        int i = 0, numVowels = maxVowel;
        for(int j = k; j <= s.length() - 1; j++){
            numVowels += isVowel(s[j]);
            numVowels -= isVowel(s[i]);
            i += 1;
            maxVowel = max(maxVowel, numVowels);
        }
        return maxVowel;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
Author: M.R.Naganathan
*/
