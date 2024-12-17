/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char, int>> maxHeap;
        unordered_map<char, int> freq;

        for(char c : s) freq[c] += 1;
        for(auto i : freq) maxHeap.push({i.first, i.second});

        string limitedString = "";
        while(!maxHeap.empty()){
            auto [currChar, remCount] = maxHeap.top();
            maxHeap.pop();

            for(int i = 1; i <= min(remCount, repeatLimit); i++) limitedString += currChar;
            remCount -= repeatLimit;
            if(remCount <= 0) continue;

            if(maxHeap.empty()) break;
            auto [secondChar, secondCount] = maxHeap.top();
            maxHeap.pop();

            limitedString += secondChar;
            secondCount -= 1;
            if(secondCount > 0) maxHeap.push({secondChar, secondCount});
            maxHeap.push({currChar, remCount});
        }
        return limitedString;
    }
};

/*
Question Link: https://leetcode.com/problems/construct-string-with-repeat-limit/
Author: M.R.Naganathan
*/
