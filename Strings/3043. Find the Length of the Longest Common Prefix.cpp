/*------------------------------
  Time Complexity: O(n * m * w)
  Space Complexity: O(n * w)
---------------------------------*/

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> hashSet;
        for(int i : arr1){
            string stringNum = to_string(i);
            string currString = "";
            for(int j = 0; j <= stringNum.length() - 1; j++){
                currString += stringNum[j];
                if(hashSet.find(currString) != hashSet.end()) continue;
                hashSet.insert(currString);
            }
        }

        int maxLen = 0;
        for(int i : arr2){
            string stringNum = to_string(i);
            string currString = "";
            for(int j = 0; j <= stringNum.length() - 1; j++){
                currString += stringNum[j];
                if(hashSet.find(currString) == hashSet.end()) continue;
                maxLen = max(maxLen, (int)currString.length());
            }
        }
        return maxLen;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
Author: M.R.Naganathan
*/
