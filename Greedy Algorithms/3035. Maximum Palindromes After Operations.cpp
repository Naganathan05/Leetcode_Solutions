/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int numWords = words.size();
        vector<int> wordLengths;
        unordered_map<char, int> freq;

        for(string &word : words) wordLengths.push_back(word.length());
        sort(wordLengths.begin(), wordLengths.end());

        for(int i = 0; i <= numWords - 1; i++){
            for(int j = 0; j <= words[i].length() - 1; j++) freq[words[i][j]] += 1;
        }

        int numEvenPairs = 0, numOdds = 0;
        for(auto &i : freq){
            numEvenPairs += (i.second / 2);
            numOdds += (i.second % 2);
        }

        int maxPalindromes = 0;
        for(int i = 0; i <= numWords - 1; i++){
            int currLen = wordLengths[i];
            if((currLen / 2) > numEvenPairs) break;
            numEvenPairs -= (currLen / 2);
            if(currLen % 2) numOdds -= 1;
            if(numOdds < 0){
                numEvenPairs -= 1;
                numOdds += 2;
            }
            maxPalindromes += 1;
        }
        return maxPalindromes;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-palindromes-after-operations/
Author: M.R.Naganathan
*/
