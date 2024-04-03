/*------------------------------------------
    Time Complexity: O(m * n * 4^L)
    Space Complexity: O(Word Length)
--------------------------------------------*/

class Solution {
public:
    bool check(vector<vector<char>> &board, int i, int j, int k, string &word){
        if(k == word.length()) return true;

        if(i < 0 || j < 0) return false;
        if(i == board.size() || j == board[0].size()) return false;

        if(board[i][j] != word[k] || board[i][j] == '0') return false;

        char temp = board[i][j];
        board[i][j] = '0';

        bool left = false, right = false, down = false, up = false;
        left = check(board, i, j - 1, k + 1, word);
        right = check(board, i, j + 1, k + 1, word);
        up = check(board, i - 1, j, k + 1, word);
        down = check(board, i + 1, j, k + 1, word);
        if (left || right || down || up) return true;

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (check(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};

/*
Question Link: https://leetcode.com/problems/word-search/description/
Author: M.R.Naganathan
*/
