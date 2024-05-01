/*----------------------------------------
  Time Complexity: O(m + n)
  Space Complexity: O(1)
-------------------------------------------*/

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i = 0, j = 0, lastPushed = -1, cnt = 0;
        while(i <= n - 1 && j <= m - 1){
            if(arr1[i] <= arr2[j]){
                lastPushed = arr1[i];
                i += 1;
            }
            else{
                lastPushed = arr2[j];
                j += 1;
            }
            cnt += 1;
            if(cnt == k) return lastPushed;
        }
        
        while(i <= n - 1){
            lastPushed = arr1[i];
            i += 1;
            cnt += 1;
            if(cnt == k) return lastPushed;
        }
        
        while(j <= n - 1){
            lastPushed = arr2[j];
            j += 1;
            cnt += 1;
            if(cnt == k) return lastPushed;
        }
        return lastPushed;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
Author: M.R.Naganathan
*/
