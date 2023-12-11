class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int cnt = 1;
        for(int i = 0; i <= arr.size() - 1; i++){
            if(arr[i] == arr[i + arr.size()/4]){
                return arr[i];
            }
        }
        return -1;
    }
};
