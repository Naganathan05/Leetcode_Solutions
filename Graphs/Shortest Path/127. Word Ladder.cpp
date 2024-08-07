/*---------------------------------------
  Time Complexity: O(n * n * maxLength)
  Space Complexity: O(n * n)
-----------------------------------------*/

class Solution {
public:
    bool ValidTransformation(string &firstWord, string &secondWord){
        int numDiff = 0;
        for(int i = 0; i <= firstWord.length() - 1; i++) numDiff += (firstWord[i] != secondWord[i]);
        return numDiff == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int numWords = wordList.size();
        unordered_map<string, vector<string>> adjList;
        
        for(int i = 0; i <= numWords - 1; i++){
            for(int j = i + 1; j <= numWords - 1; j++){
                if(ValidTransformation(wordList[i], wordList[j])){
                    adjList[wordList[i]].push_back(wordList[j]);
                    adjList[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        for(int i = 0; i <= numWords - 1; i++){
            if(ValidTransformation(beginWord, wordList[i])){
                adjList[beginWord].push_back(wordList[i]);
                adjList[wordList[i]].push_back(beginWord);
            }
        }

        queue<string> fifo;
        unordered_map<string, bool> visited;
        fifo.push(beginWord);
        visited[beginWord] = true;
        int totalCost = 1;

        while(!fifo.empty()){
            int levelSize = fifo.size();
            for(int i = 0; i < levelSize; i++){
                string currString = fifo.front();
                fifo.pop();

                if(currString == endWord) return totalCost;

                for(string neighbour : adjList[currString]){
                    if(!visited[neighbour]){
                        visited[neighbour] = true;
                        fifo.push(neighbour);
                    }
                }
            }
            totalCost += 1;
        }
        return 0;
    }
};

/*
Question Link: https://leetcode.com/problems/word-ladder/
Author: M.R.Naganathan
*/
