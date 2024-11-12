/*----------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-------------------------------*/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<int> maxItems(queries.size(), 0);
        vector<int> maxBeauty(items.size(), items[0][1]);
        for(int i = 1; i <= items.size() - 1; i++) maxBeauty[i] = max(maxBeauty[i - 1], items[i][1]);
        vector<int> sortedPrices;
        for(auto i : items) sortedPrices.push_back(i[0]);
        for(int i = 0; i <= queries.size() - 1; i++){
            int ind = upper_bound(sortedPrices.begin(), sortedPrices.end(), queries[i]) - sortedPrices.begin();
            if(ind == 0) continue; 
            cout << queries[i] << " " << ind << endl;
            maxItems[i] = maxBeauty[ind - 1];
        }
        return maxItems;
    }
};

/*
Question Link: https://leetcode.com/problems/most-beautiful-item-for-each-query/
Author: M.R.Naganathan
*/
