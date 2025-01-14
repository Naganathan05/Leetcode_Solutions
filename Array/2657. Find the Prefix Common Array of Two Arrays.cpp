/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> prefixCommon(A.size(), 0);
        unordered_map<int, int> freq;

        int numMatches = 0;
        for(int i = 0; i <= A.size() - 1; i++){
            freq[A[i]] -= 1;
            freq[B[i]] += 1;
            // cout << A[i] << " " << freq[A[i]] << " " << B[i] << " " << freq[B[i]] << endl;

            if(freq[A[i]] == 0 && A[i] == B[i]) numMatches += 1;
            else if(freq[A[i]] == 0) numMatches += 1;
            if(freq[B[i]] == 0 && A[i] != B[i]) numMatches += 1;
            prefixCommon[i] = numMatches;
        }
        return prefixCommon;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
Author: M.R.Naganathan
*/
