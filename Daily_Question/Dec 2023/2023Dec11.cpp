class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        for(int i = 0; i <= arr.size() - 1; i++){
            if(arr[i] == arr[i + arr.size()/4]){
                return arr[i];
            }
        }
        return -1;
    }
};


// Question Link: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/?envType=daily-question&envId=2023-12-11
