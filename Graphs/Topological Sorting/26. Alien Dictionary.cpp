/*----------------------------------
  Time Complexity: O(n)
  Space Complexity: O(k)
------------------------------------*/

class Solution {
public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adjList(K);
        vector<int> inDegrees(K, 0);
        
        for(int i = 0; i < N - 1; i++){
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int minLen = min(s1.length(), s2.length());
            for(int j = 0; j < minLen; j++){
                if(s1[j] != s2[j]){
                    adjList[s1[j] - 'a'].push_back(s2[j] - 'a');
                    inDegrees[s2[j] - 'a'] += 1;
                    break;
                }
            }
        }
        
        queue<int> q;
        for(int i = 0; i < K; i++) {
            if(inDegrees[i] == 0) q.push(i);
        }
        
        string topoSort = "";
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topoSort += (char)(node + 'a');
            for(int neighbor : adjList[node]) {
                inDegrees[neighbor] -= 1;
                if(inDegrees[neighbor] == 0) q.push(neighbor);
            }
        }
        
        return topoSort.length() == K ? topoSort : "";
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/alien-dictionary/1
Author: M.R.Naganathan
*/
