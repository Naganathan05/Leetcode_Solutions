/*---------------------------
  Time Complexity: O(nlogn)  
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int minRadius = 0;
        for(int i = 0; i <= houses.size() - 1; i++){
            int currHouse = houses[i];
            int ind = lower_bound(heaters.begin(), heaters.end(), currHouse) - heaters.begin();
            cout << "Lower Bound Of " << currHouse << ": " << ind << endl;
            int currRadius = 1e9;
            if(ind < heaters.size()) currRadius = abs(currHouse - heaters[ind]);
            if(ind > 0) currRadius = min(currRadius, (currHouse - heaters[ind - 1]));
            minRadius = max(currRadius, minRadius);
        }
        return minRadius;
    }
};

/*
Question Link: https://leetcode.com/problems/heaters/
Author: M.R.Naganathan
*/
