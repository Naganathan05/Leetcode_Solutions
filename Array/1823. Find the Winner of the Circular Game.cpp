/*------------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n)
---------------------------------*/

class Solution {
public:
    int findTheWinner(int n, int k) {
        int currPlayer = 0, numPlayers = n;
        vector<bool> Eliminated(n, false);

        while(numPlayers > 1){
            int cnt = 0;
            while(cnt < k) {
                if (!Eliminated[currPlayer]) cnt += 1;
                if (cnt == k) break;
                currPlayer = (currPlayer + 1) % n;
            }
            Eliminated[currPlayer] = true;
            numPlayers -= 1;
            while (Eliminated[currPlayer]) currPlayer = (currPlayer + 1) % n;
        }
        return currPlayer + 1;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
Author: M.R.Naganathan
*/
