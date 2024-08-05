/*------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
--------------------------------*/

class Solution {
public:
    int findPlatform(int arr[], int dep[], int n) {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int platforms_needed = 0;
        int max_platforms = 0;

        int i = 0, j = 0;
        
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platforms_needed += 1;
                i += 1;
            }
            else {
                platforms_needed -= 1;
                j += 1;
            }
            max_platforms = max(max_platforms, platforms_needed);
        }
        return max_platforms;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
Author: M.R.Naganathan
*/
