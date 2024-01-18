/*------------------------------------------------------------
  Time Complexity: O(n) => n:Number Of Elements in the Array
  Space Complexity: O(n)
-------------------------------------------------------------*/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int count = 0;
        for(int i = 0; i <= arr.size() - 1; i++){
            freq[arr[i]]++;
        }
        // Min Heap for storing the frequencies in ascending sorted order
        priority_queue<int, vector<int>, greater<int>> queue;
        for(auto i : freq){
            queue.push(i.second);
        }
        while(!queue.empty() && k > 0){
            if(queue.top() <= k){
                k -= queue.top();
                count += 1;
            }
            queue.pop();
        }
        return freq.size() - count;
    }
};

/*
Question Link: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/
Author: M.R.Naganathan
*/
