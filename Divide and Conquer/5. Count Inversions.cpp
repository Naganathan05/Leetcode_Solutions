/*--------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
  public:
    long long int merge(vector<long long> &arr, int low, int mid, int high) {
        vector<long long> temp;
        int left = low;
        int right = mid + 1;
        long long int numInversions = 0;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left += 1;
            } else {
                numInversions += (mid - left + 1);
                temp.push_back(arr[right]);
                right += 1;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left += 1;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right += 1;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return numInversions;
    }

    long long int mergeSort(vector<long long> &arr, int low, int high) {
        long long int numInversions = 0;
        if (low >= high) return 0;
        
        int mid = low + (high - low) / 2;
        numInversions += mergeSort(arr, low, mid);
        numInversions += mergeSort(arr, mid + 1, high);
        numInversions += merge(arr, low, mid, high);
        
        return numInversions;
    }

    long long int inversionCount(vector<long long> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
Author: M.R.Naganathan
*/
