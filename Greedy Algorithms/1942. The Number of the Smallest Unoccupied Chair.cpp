/*----------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-------------------------------*/

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int numPersons = times.size();
        vector<pair<int, int>> startTimes;
        vector<pair<int, int>> endTimes;

        for(int i = 0; i <= times.size() - 1; i++){
            startTimes.push_back({times[i][0], i});
            endTimes.push_back({times[i][1], i});
        }

        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());
        unordered_map<int, int> personChairMapping;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = 0; i <= numPersons - 1; i++) minHeap.push(i);

        int i = 0, j = 0;
        while(i < times.size() && j < times.size()){
            if(startTimes[i].first < endTimes[j].first){
                int nextChair = minHeap.top();
                minHeap.pop();
                personChairMapping[startTimes[i].second] = nextChair;
                if(startTimes[i].second == targetFriend) return nextChair;
                i += 1;
            }
            else{
                int removeChair = personChairMapping[endTimes[j].second];
                minHeap.push(removeChair);
                j += 1;
            }
        }
        return 0;
    }
};

/*
Qustion Link: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/
Author: M.R.Naganathan
*/
