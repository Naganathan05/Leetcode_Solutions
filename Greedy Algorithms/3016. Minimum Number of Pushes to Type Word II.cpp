/*------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
---------------------------------*/

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        for(char c : word) freq[c] += 1;
        vector<pair<int, char>> sortedFreq;
        for(auto i : freq) sortedFreq.push_back({i.second, i.first});
        sort(sortedFreq.begin(), sortedFreq.end());

        int currCost = 1, totalCost = 0, numPushes = 1;
        for(int i = sortedFreq.size() - 1; i >= 0; i--){
            totalCost += (currCost * sortedFreq[i].first);
            numPushes += 1;
            if(numPushes > 8){
                currCost += 1;
                numPushes = 1;
            }
        }
        return totalCost;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
Author: M.R.Naganathan
*/
