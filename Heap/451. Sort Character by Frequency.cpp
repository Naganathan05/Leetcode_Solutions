/*-----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
------------------------------------------------*/

class Solution {
public:
    string frequencySort(string s) {
        string str = "";
        map<char, int> freq;
        for(int i = 0; i <= s.size() - 1; i++){
            freq[s[i]]++;
        }
        priority_queue<pair<int, char>> queue;
        for(auto i : freq){
            queue.push(pair(i.second, i.first));
        }
        while(!queue.empty()){
            int f = queue.top().first;
            while(f){
                str += queue.top().second;
                f--;
            }
            queue.pop();
        }
        return str;
    }
};

/*
Question Link: https://leetcode.com/problems/sort-characters-by-frequency/description/
Author: M.R.Naganathan
*/
