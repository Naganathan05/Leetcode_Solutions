'''-------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
---------------------------------------------'''

class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        left = right = 0
        for i in range(len(s)):           
            if i >= len(s)/2:
                if s[i] in "AEIOUaeiou":
                    right += 1
            else:
                if s[i] in "AEIOUaeiou":
                    left += 1
        return left == right

'''
Question Link: https://leetcode.com/problems/determine-if-string-halves-are-alike/description/?envType=daily-question&envId=2024-01-12
Author: M.R.Naganathan
'''
