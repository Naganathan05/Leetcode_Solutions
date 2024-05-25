/*-----------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-------------------------------------*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;
        for(int s : stones) max_heap.push(s);

        while(!max_heap.empty()){
            int x = max_heap.top();
            max_heap.pop();
            if(max_heap.empty()) return x;
            int y = max_heap.top();
            max_heap.pop();
            max_heap.push(abs(x - y));
        } 
        return 0;
    }
};

/*
Question Link: https://leetcode.com/problems/last-stone-weight/
Author: M.R.Naganathan
*/
