/*--------------------------------
Method: Memoization
  Time Complexity: O(n)
  Space Complexity: O(n) + O(n)
----------------------------------*/

func solveQuestion(questions [][]int, i int, dp []int64) int64 {
    if i >= len(questions) {
        return 0;
    }

    if dp[i] != -1 {
        return dp[i];
    }

    Pick := int64(questions[i][0]) + solveQuestion(questions, i + questions[i][1] + 1, dp);
    noPick := solveQuestion(questions, i + 1, dp);
    dp[i] = max(Pick, noPick);
    return dp[i];
}

func mostPoints(questions [][]int) int64 {
    numQuestions := len(questions);
    dp := make([]int64, numQuestions);
    for i := range dp {
        dp[i] = -1;
    }
    return solveQuestion(questions, 0, dp);
}

/*---------------------------
Method: Tabulation
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------*/

func mostPoints(questions [][]int) int64 {
    numQuestions := len(questions);
    dp := make([]int64, numQuestions + 1);
    for i := range dp {
        dp[i] = -1;
    }
    dp[numQuestions] = 0;

    for i := numQuestions - 1; i >= 0; i-- {
        Pick := int64(questions[i][0]);
        if i + questions[i][1] + 1 < numQuestions {
            Pick += dp[i + questions[i][1] + 1];
        }
        noPick := dp[i + 1];
        dp[i] = max(Pick, noPick);
    }
    return dp[0];
}

/*
Question Link: https://leetcode.com/problems/solving-questions-with-brainpower/description/
Author: M.R.Naganathan
*/
