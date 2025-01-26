/*--------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<int> offlineUntil(numberOfUsers, 0);

        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int timeA = stoi(a[1]);
            int timeB = stoi(b[1]);
            if (timeA != timeB) return timeA < timeB;
            return a[0] == "OFFLINE";
        });

        for (const auto& event : events) {
            string type = event[0];
            int timestamp = stoi(event[1]);

            if (type == "OFFLINE") {
                int userId = stoi(event[2]);
                offlineUntil[userId] = timestamp + 60;
            } 
            else if (type == "MESSAGE") {
                string mentionsStr = event[2];

                if (mentionsStr == "ALL") {
                    for (int i = 0; i < numberOfUsers; ++i) mentions[i] += 1;
                } 
                else if (mentionsStr == "HERE") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        mentions[i] += (timestamp >= offlineUntil[i]);
                    }
                } 
                else {
                    int i = 0, n = mentionsStr.size();
                    while (i < n) {
                        if (mentionsStr[i] == 'i' && mentionsStr[i + 1] == 'd') {
                            int userId = 0;
                            i += 2;
                            while (i < n && isdigit(mentionsStr[i])) {
                                userId = userId * 10 + (mentionsStr[i] - '0');
                                i += 1;
                            }
                            mentions[userId] += (userId >= 0 && userId < numberOfUsers);
                        } 
                        else i += 1;
                    }
                }
            }
        }
        return mentions;
    }
};

/*
Question Link: https://leetcode.com/problems/count-mentions-per-user/
Author: M.R.Naganathan
*/
