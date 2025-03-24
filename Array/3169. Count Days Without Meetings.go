/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
-----------------------------*/

func countDays(days int, meetings [][]int) int {
    sort.Slice(meetings, func(i, j int) bool {
        if meetings[i][0] == meetings[j][0] {
            return meetings[i][1] < meetings[j][1];
        }
        return meetings[i][0] < meetings[j][0];
    })

    // fmt.Println(meetings);
    lastEndTime, numFreeDays := meetings[0][1], (meetings[0][0] - 1);
    for i := 1; i < len(meetings); i++ {
        if meetings[i][0] > lastEndTime {
            numFreeDays += (meetings[i][0] - lastEndTime - 1);
        }
        lastEndTime = max(lastEndTime, meetings[i][1]);
    }
    numFreeDays += (days - lastEndTime);
    return numFreeDays;
}

/*
Question Link: https://leetcode.com/problems/count-days-without-meetings/
Author: M.R.Naganathan
*/
