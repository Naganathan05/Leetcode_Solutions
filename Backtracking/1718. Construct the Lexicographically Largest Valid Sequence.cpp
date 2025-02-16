/*--------------------------
  Time Complexity: O(n!)
  Space Complexity: O(n)
----------------------------*/

class Solution {
public:
    bool found = false;
    void backtrack(vector<int> &seq, int i, vector<bool> &visited) {
        if (found) return;
        if (i == seq.size()) {
            found = true;
            return;
        }

        if (seq[i] != -1) {
            backtrack(seq, i + 1, visited);
            return;
        }

        for (int num = seq.size() / 2 + 1; num >= 1; num--) {
            if (visited[num]) continue;

            visited[num] = true;
            seq[i] = num;

            if (num == 1 || (i + num < seq.size() && seq[i + num] == -1)) { 
                if (num > 1) seq[i + num] = num;
                backtrack(seq, i + 1, visited);
                if (found) return;
                if (num > 1) seq[i + num] = -1;
            }

            seq[i] = -1;
            visited[num] = false;
        }
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> seq((2 * n) - 1, -1);
        vector<bool> visited(n + 1, false);
        backtrack(seq, 0, visited);
        return seq;
    }
};

/*
Question Link: https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/
Author: M.R.Naganathan
*/
