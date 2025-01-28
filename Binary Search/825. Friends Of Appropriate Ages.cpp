
    /*
    Time complexity : O(nlogn)
    Space complexity : O(n)
    */


class Solution {
public:
    int lowerBound(vector<int> &ages, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ages[mid] >= target) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }

    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int numFriendRequests = 0;

        for (int i = 0; i < ages.size();) {
            int target = (0.5 * ages[i]) + 7;
            if (target >= ages[i]){
                i += 1;
                continue;
            }

            int j = i + 1;
            while(j < ages.size() && ages[i] == ages[j]) j += 1;

            int validStartIndex = lowerBound(ages, 0, i - 1, target + 1);
            int numDuplicates = (j - i);
            numFriendRequests += (numDuplicates * (numDuplicates - 1));
            numFriendRequests += ((i - validStartIndex) * numDuplicates);
            i = j;
        }
        return numFriendRequests;
    }
};


    /*
    Author : Naganathan05
    Question Link : https://leetcode.com/problems/friends-of-appropriate-ages/
    */

    