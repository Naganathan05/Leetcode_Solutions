/*----------------------------------
n = Number of Rooms Available
m = Number of Meetings
  Time Complexity: O(mlogm + mlogn)
  Space Complexity: O(m + n)
-------------------------------------*/

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, int>,
                        vector<pair<long long, int>>,
                        greater<pair<long long, int>>> activeMeetings;

        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for(int i = 0; i < n; i++) freeRooms.push(i);

        unordered_map<int, int> meetingCount;
        for(auto &meeting : meetings) {
            long long startTime = meeting[0];
            long long endTime = meeting[1];

            // Push all rooms where meeting have ended by now
            while(!activeMeetings.empty() && activeMeetings.top().first <= startTime) {
                freeRooms.push(activeMeetings.top().second);
                activeMeetings.pop();
            }

            // Allocate Room
            if(!freeRooms.empty()) {
                int currMeetingRoom = freeRooms.top();
                freeRooms.pop();
                activeMeetings.push({endTime, currMeetingRoom});
                meetingCount[currMeetingRoom] += 1;
            } else {
                long long soonestMeetingEndTime = activeMeetings.top().first;
                int currMeetingRoom = activeMeetings.top().second;
                long long newEndTime = (long long) endTime + (soonestMeetingEndTime - startTime);
                activeMeetings.pop();
                activeMeetings.push({newEndTime, currMeetingRoom});
                meetingCount[currMeetingRoom] += 1;
            }
        }

        int maxMeetingCount = -1;
        int meetingRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetingCount) {
                maxMeetingCount = meetingCount[i];
                meetingRoom = i;
            }
        }
        return meetingRoom;
    }
};

/*
Question Link: https://leetcode.com/problems/meeting-rooms-iii/
Author: M.R.Naganathan
*/
