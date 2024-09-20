/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, pair<int, int>> groupIndex;
        vector<vector<int>> ans;
        int j = 0;
        for(int i = 0; i <= groupSizes.size() - 1; i++){
            int groupCapacity = groupSizes[i];
            if(groupIndex.find(groupCapacity) == groupIndex.end() || groupIndex[groupCapacity].second == 0){
                vector<int> currGroup;
                currGroup.push_back(i);
                groupIndex[groupCapacity] = {j, groupCapacity - 1};
                ans.push_back(currGroup);
                j += 1;
            }
            else{
                int insertPosition = groupIndex[groupCapacity].first;
                int currCapacity = groupIndex[groupCapacity].second;
                ans[insertPosition].push_back(i);
                groupIndex[groupCapacity] = {insertPosition, currCapacity - 1};
            }
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
Author: M.R.Naganathan
*/
