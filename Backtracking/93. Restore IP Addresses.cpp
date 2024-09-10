/*--------------------------
  Time Complexity: O(2 ^ n)
  Space Complexity: O(2 ^ n)
-----------------------------*/

class Solution {
public:
    bool checkLeadingZeroes(string &IP) {
        return (IP.length() > 1 && IP[0] == '0');
    }

    void Restore(string &s, int i, int numPartitions, string &currIP, vector<string> &IP) {
        if (i == s.length()) {
            if (numPartitions != 4) return;
            IP.push_back(currIP.substr(1)); 
            return;
        }

        for (int j = i; j <= min(i + 3, (int)s.length() - 1); j++) {
            string temp = currIP;
            string currPart = s.substr(i, j - i + 1);
            if (checkLeadingZeroes(currPart) || stoi(currPart) > 255) continue;
            currIP += ('.' + currPart);
            Restore(s, j + 1, numPartitions + 1, currIP, IP);
            currIP = temp;
        }
        return;
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.length() > 12) return {};
        string currIP = "";
        vector<string> IP;
        Restore(s, 0, 0, currIP, IP);
        return IP;
    }
};

/*
Question Link: https://leetcode.com/problems/restore-ip-addresses/
Author: M.R.Naganathan
*/
