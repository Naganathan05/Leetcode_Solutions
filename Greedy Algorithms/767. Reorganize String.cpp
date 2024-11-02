/*----------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> maxHeap;
        unordered_map<char, int> freq;
        for(char c : s) freq[c] += 1;

        for(auto i : freq) maxHeap.push({i.second, i.first});
        string reorganizedString = "";
        while(!maxHeap.empty()){
            auto [firstCount, firstChar] = maxHeap.top();
            maxHeap.pop();
            reorganizedString += firstChar;
            if(maxHeap.empty() && firstCount > 1) return "";
            if(!maxHeap.empty()){
                auto [secondCount, secondChar] = maxHeap.top();
                maxHeap.pop();
                reorganizedString += secondChar;
                if(secondCount > 1) maxHeap.push({secondCount - 1, secondChar});
            }
            if(firstCount > 1) maxHeap.push({firstCount - 1, firstChar}); 
        }
        return reorganizedString;
    }
};

/*
Question Link: https://leetcode.com/problems/reorganize-string/
Author: M.R.Naganathan
*/
