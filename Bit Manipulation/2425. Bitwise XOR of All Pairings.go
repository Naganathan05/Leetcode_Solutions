/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------*/

func xorAllNums(nums1 []int, nums2 []int) int {
    needFirstXOR := len(nums2) % 2 != 0;
    needSecondXOR := len(nums1) % 2 != 0;

    firstTotalXOR := 0;
    secondTotalXOR := 0;

    for _, num := range nums1 {
        firstTotalXOR ^= num;
    }

    for _, num := range nums2 {
        secondTotalXOR ^= num;
    }

    answer := 0;
    if needFirstXOR {
        answer ^= firstTotalXOR;
    }
    if (needSecondXOR) {
        answer ^= secondTotalXOR;
    }
    return answer;
}

/*
Question Link: https://leetcode.com/problems/bitwise-xor-of-all-pairings/
Author: M.R.Naganathan
*/
