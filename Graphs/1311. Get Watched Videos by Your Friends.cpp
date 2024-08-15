/*-----------------------------
  Time Complexity: O(V + E)
  Space ComplexityL O(V + E)
--------------------------------*/

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        queue<int> fifo;
        vector<bool> visited(n, false);
        unordered_map<string, int> freq;
        fifo.push(id);
        visited[id] = true;
        int currLevel = 0;

        while(!fifo.empty()){
            int size = fifo.size();
            if(currLevel == level) break;

            for(int i = 0; i < size; i++){
                int node = fifo.front();
                fifo.pop();

                for(int frd : friends[node]){
                    if(!visited[frd]){
                        fifo.push(frd);
                        visited[frd] = true;
                    }
                }
            }
            currLevel += 1;
        }

        while(!fifo.empty()){
            int node = fifo.front();
            fifo.pop();
            for(const string& video : watchedVideos[node]) freq[video] += 1;
        }

        vector<pair<string, int>> freqVector(freq.begin(), freq.end());
        sort(freqVector.begin(), freqVector.end(), [](pair<string, int>& a, pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });

        vector<string> ans;
        for(auto& p : freqVector) ans.push_back(p.first);
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/get-watched-videos-by-your-friends/
Author: M.R.Naganathan
*/
