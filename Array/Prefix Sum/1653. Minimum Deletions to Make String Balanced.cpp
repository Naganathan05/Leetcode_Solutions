/*--------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int minimumDeletions(string s) {
        int num_a = 0, num_b = 0;
        vector<int> count_a(s.length(), 0);
        vector<int> count_b(s.length(), 0);

        for(int i = 0; i <= s.length() - 1; i++){
            count_b[i] = num_b;
            num_b += (s[i] == 'b');
        }

        for(int i = s.length() - 1; i >= 0; i--){
            count_a[i] = num_a;
            num_a += (s[i] == 'a');
        }

        int minDeletions = s.length();
        for(int i = 0; i <= s.length() - 1; i++) minDeletions = min(minDeletions, count_a[i] + count_b[i]);
        return minDeletions;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
Author: M.R.Naganathan
*/
