/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------*/

func bestClosingTime(customers string) int {
	totalIncomings := 0;
	for _, c := range customers {
		if c == 'Y' {
			totalIncomings += 1;
		}
	}

	currCustomerCount := 0;
	if customers[0] == 'Y' {
		currCustomerCount = 1;
	}
	currEmptyHours := 0;
	if customers[0] == 'N' {
		currEmptyHours = 1;
	}

	minPenalty := totalIncomings;
	closeHour := 0;

	for i := 1; i <= len(customers); i++ {
		currPenalty := (totalIncomings - currCustomerCount) + currEmptyHours;
		if currPenalty < minPenalty {
			minPenalty = currPenalty;
			closeHour = i;
		}

		if i == len(customers) {
			continue;
		}
		if customers[i] == 'Y' {
			currCustomerCount += 1;
		}
		if customers[i] == 'N' {
			currEmptyHours += 1;
		}
	}
	return closeHour;
}

/*
Question Link: https://leetcode.com/problems/minimum-penalty-for-a-shop/
Author: M.R.Naganathan
*/
