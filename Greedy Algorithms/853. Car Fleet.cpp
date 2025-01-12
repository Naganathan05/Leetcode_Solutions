/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> carData;
        for(int i = 0; i <= position.size() - 1; i++){
            carData.push_back({position[i], (double) (target - position[i]) / speed[i]});
        }

        sort(carData.begin(), carData.end(), [](const pair<int, double> &a, const pair<int, double> &b){
            return a.first > b.first;
        });

        int numFleets = 1;
        double maxTime = carData[0].second;
        for(int i = 1; i <= carData.size() - 1; i++){
            if(carData[i].second > maxTime){
                numFleets += 1;
                maxTime = carData[i].second;
            }
        }
        return numFleets;
    }
};

/*
Question Link: https://leetcode.com/problems/car-fleet/
Author: M.R.Naganathan
*/
