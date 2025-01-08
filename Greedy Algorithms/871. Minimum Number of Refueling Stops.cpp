/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    int addFuel(int dest, int src, int &remFuel, priority_queue<int> &maxHeap){
        int numRefuels = 0;
        while(dest - src > remFuel){
            if(maxHeap.empty()) return -1;
            cout << "Added Fuel of: " << maxHeap.top() << endl;
            remFuel += maxHeap.top();
            maxHeap.pop();
            numRefuels += 1; 
        }
        return numRefuels;
    }


    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxHeap;
        int numStations = stations.size();

        int remFuel = startFuel, currPos = 0, i = 0;
        int numRefuels = 0;
        for(int  i = 0; i <= numStations - 1 && currPos < target; i++){
            int additionalStops = addFuel(stations[i][0], currPos, remFuel, maxHeap);
            if(additionalStops == -1) return -1;
            numRefuels += additionalStops;

            remFuel -= (stations[i][0] - currPos);
            currPos = stations[i][0];
            maxHeap.push(stations[i][1]);
        }

        if(currPos < target){
            int additionalStops = addFuel(target, currPos, remFuel, maxHeap);
            if(additionalStops == -1) return -1;
            numRefuels += additionalStops;
        }
        return numRefuels;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-number-of-refueling-stops/
Author: M.R.Naganathan
*/
