/*---------------------------
  Time Complexity: O(2 ^ n)
  Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    bool partitionNumber(string &num, int i, int currSum, int &target){
        if(i == num.length()) return (currSum == target);

        string currNum = "";
        for(int j = i; j < num.length(); j++){
            currNum += num[j];
            currSum += stoi(currNum);
            if(partitionNumber(num, j + 1, currSum, target)) return true;
            currSum -= stoi(currNum);
        }
        return false;
    }

    int punishmentNumber(int n) {
        int punNumber = 0;
        for(int i = 1; i <= n; i++){
            string currNum = to_string((i * i));
            if(partitionNumber(currNum, 0, 0, i)) punNumber += (i * i);
        }
        return punNumber;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-punishment-number-of-an-integer/
Author: M.R.Naganathan
*/
