/*---------------------------------
  Time Complexity: O(nlogk)
  Space Complexity: O(n)
-----------------------------------*/

class cmp{
    public:
    bool operator()(pair<int,string> a, pair<int,string> b) const
    {
        if(a.first < b.first) return true;
        else if(a.first == b.first && a.second > b.second) return true;
        return false;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(string str : words) freq[str] += 1;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        for(auto i : freq) pq.push({i.second, i.first});
        vector<string> ans;
        while(k){
            string str = pq.top().second;
            pq.pop();
            ans.push_back(str);
            k -= 1;
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/top-k-frequent-words/
Author: M.R.Naganathan
*/
