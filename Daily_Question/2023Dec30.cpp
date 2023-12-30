/*-------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
---------------------------------------------*/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if(words.size() <= 1){
            return true;
        }

        int total_count = 0;
        for(string str: words){
            total_count += str.length();
        }
        if(total_count % (words.size()) != 0){
            return false;
        }

        map<char, int> freq;
        for(string str: words){
            for(char c: str){
                freq[c]++;
            }
        }

        for(auto c: freq){
            if(c.second % (words.size()) != 0){
                return false;
            }
        }
        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/?envType=daily-question&envId=2023-12-30
Author: M.R.Naganathan
*/
