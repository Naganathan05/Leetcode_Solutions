/*------------------------------------
  n = Number of Classes
  m = Number of Extra Students
  Time Complexity: O((m + n) log n)
  Space Complexity: O(n)
---------------------------------------*/

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int numClasses = classes.size();
        priority_queue<pair<double, pair<int, int>>> maxHeap;

        double passRatioSum = 0.0;
        for (int i = 0; i < numClasses; i++) {
            double passRatio = (double)classes[i][0] / classes[i][1];
            double gain = (double)(classes[i][0] + 1) / (classes[i][1] + 1) - passRatio;
            maxHeap.push({gain, {classes[i][0], classes[i][1]}});
            passRatioSum += passRatio;
        }

        while (extraStudents) {
            auto [gain, classInfo] = maxHeap.top();
            auto [passCount, totalStudents] = classInfo;
            maxHeap.pop();

            passRatioSum -= (double)passCount / totalStudents;

            passCount += 1;
            totalStudents += 1;
            extraStudents -= 1;

            passRatioSum += (double)passCount / totalStudents;

            double newGain = (double)(passCount + 1) / (totalStudents + 1) - (double)passCount / totalStudents;
            maxHeap.push({newGain, {passCount, totalStudents}});
        }

        double result = passRatioSum / numClasses;
        return round(result * 1e5) / 1e5;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-average-pass-ratio/
Author: M.R.Naganathan
*/
