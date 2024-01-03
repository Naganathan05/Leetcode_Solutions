/*---------------------------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(n)
----------------------------------------------*/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        map<int, int> row_device;
        int ans = 0;

        for(int i = 0; i <= bank.size() - 1;  i++){
            for(int j = 0; j <= bank[i].length() - 1; j++){
                if(bank[i][j] == '1'){
                    row_device[i]++;
                }
            }
        }

        for(int i = 0; i <= bank.size() - 1; i++){
            for(int j = i + 1; j <= bank.size() - 1; j++){
                if(row_device[j] >= 1 && row_device[i] >= 1){
                    ans += row_device[i]*row_device[j];
                    break;
                }
            }
        }

        return ans;
    }
};



/*-----------------------------------------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(n)
  Note: Referred Solution for this approach
-------------------------------------------------------------*/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> row_device;
        int ans = 0;

        for(int i = 0; i <= bank.size() - 1;  i++){
            int cnt = 0;
            for(int j = 0; j <= bank[i].length() - 1; j++){
                if(bank[i][j] == '1'){
                    cnt++;
                }
            }
            if(cnt != 0){
                row_device.push_back(cnt);
            }    
        }

        if(row_device.size() == 0){
            return 0;
        }

        for(int i = 1; i <= row_device.size() - 1; i++){
            ans += row_device[i]*row_device[i - 1];
        }

        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/?envType=daily-question&envId=2024-01-03
Author: M.R.Naganathan
*/
