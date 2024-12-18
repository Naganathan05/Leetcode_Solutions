/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------*/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int, int>> filo;
        vector<int> answer;
        for(int i : prices) answer.push_back(i);

        for(int i = 0; i <= prices.size() - 1; i++){
            int currItem = prices[i];
            while(!filo.empty() && filo.top().first >= currItem){
                auto [itemPrice, ind] = filo.top();
                filo.pop();
                answer[ind] = itemPrice - currItem;
            }
            filo.push({currItem, i});
        }
        return answer;
    }
};

/*
Question Link: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
Author: M.R.Naganathan
*/
