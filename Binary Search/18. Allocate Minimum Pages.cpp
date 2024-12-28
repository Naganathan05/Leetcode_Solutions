/*-----------------------------
  Time Complexity: O(n*sum(n))
  Space Complexity: O(1)
--------------------------------*/

class Solution {
  public:
    bool validatePartition(vector<int> &arr, int k, int maxPages){
        int currPages = 0, numSplits = 1;
        for(int i = 0; i <= arr.size() - 1; i++){
            if(currPages + arr[i] <= maxPages) currPages += arr[i];
            else {
                numSplits += 1;
                currPages = arr[i];
            }
        }
        return numSplits <= k;
    }
  
    int findPages(vector<int> &arr, int k) {
        if(arr.size() < k) return -1;
        int low = -1e9, high = 0;
        for(int i : arr){
            low = max(i, low);
            high += i;
        }
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(validatePartition(arr, k, mid)) high = mid - 1;
            else low = mid + 1;
        }
        return ans;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
Author: M.R.Naganathan
*/
