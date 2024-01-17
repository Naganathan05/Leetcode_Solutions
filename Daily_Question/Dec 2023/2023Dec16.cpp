/*--------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
-----------------------------------*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s == t){
            return true;
        }
        return false;
    }
};




/*--------------------------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
  Note: Solved in this time complexity by referring to solution
----------------------------------------------------------------*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int *freq = new int[26];

        if(s.length() != t.length()){
            return false;
        }

        for(int i = 0; i <= s.length() - 1; i++){
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i <= t.length() - 1; i++){
            freq[t[i] - 'a']--;
        }

        for(int i = 0; i <= 25; i++){
            if(freq[i] != 0){
                return false;
            }
        }
        return true;
    }
};

/* Question Link: https://leetcode.com/problems/valid-anagram/?envType=daily-question&envId=2023-12-16
   Author: M.R.Naganathan
*/
