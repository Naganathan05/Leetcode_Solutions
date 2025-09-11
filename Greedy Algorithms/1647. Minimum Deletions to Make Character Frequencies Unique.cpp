/*-------------------------------
  Time Complexity: O(n * logn)
  Space Complexity: O(26)
---------------------------------*/

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freq;
        for(char c : s) freq[c] += 1;

        vector<int> frequencies;
        for(auto i : freq) frequencies.push_back(i.second);

        sort(frequencies.begin(), frequencies.end());
        unordered_set<int> seenFrequencies;

        int numDeletions = 0;
        for(auto frequency : frequencies) {
            while(frequency > 0 && seenFrequencies.find(frequency) != seenFrequencies.end()) {
                frequency -= 1;
                numDeletions += 1;
            }
            seenFrequencies.insert(frequency);
        }
        return numDeletions;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
Author: M.R.Naganathan
*/
