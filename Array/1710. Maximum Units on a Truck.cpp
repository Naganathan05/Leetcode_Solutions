/*--------------------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
-----------------------------------------------*/

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);

        int i = 0, ans = 0, flag = 0;
        while(i <= boxTypes.size() - 1 && !flag){
            if(truckSize > 0){
                int temp = boxTypes[i][0];
                while(truckSize != 0 && temp){
                    ans += (boxTypes[i][1]);
                    truckSize -= 1;
                    temp -= 1;
                }
            }
            else{
                flag = 1;
            }
            i += 1;
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-units-on-a-truck/
Author: M.R.Naganathan
*/
