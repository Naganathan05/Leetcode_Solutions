/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
------------------------------------------------*/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        int min_set = 0, removed_ele = 0;
        for(int i = 0; i <= arr.size() - 1; i++){
            freq[arr[i]]++;
        }
        priority_queue<int> queue;
        for(auto i : freq){
            queue.push(i.second);
        }
        while(!queue.empty()){
            removed_ele += queue.top();
            queue.pop();
            min_set += 1;
            if(removed_ele >= arr.size()/2){
                break;
            }
        }
        return min_set;
    }
};

/*
Question Link: https://leetcode.com/problems/reduce-array-size-to-the-half/
Author: M.R.Naganathan
*/
