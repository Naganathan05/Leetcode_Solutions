/*------------------------------------
  Time Complexity: O(n * L^2 + nlogn)
  Space Complexity: O(n * L)
---------------------------------------*/

class Node {
private:
    vector<Node*> links;
    bool isEnd;
public:
    Node() : links(26, NULL), isEnd(false) {}

    bool containsLink(char c) {
        return links[c - 'a'] != NULL;
    }

    void putLink(char c, Node* node) {
        links[c - 'a'] = node;
    }

    Node* getLink(char c) {
        return links[c - 'a'];
    }

    bool checkEnd() {
        return isEnd;
    }

    void setEnd() {
        isEnd = true;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insertWord(string &word) {
        Node* currNode = root;
        for (int i = 0; i < word.length(); i++) {
            if (!currNode -> containsLink(word[i])) currNode -> putLink(word[i], new Node());
            currNode = currNode -> getLink(word[i]);
        }
        currNode -> setEnd();
        return;
    }

    bool checkConcat(string &searchWord) {
        return DFS(searchWord, root, 0, 0);
    }

    bool DFS(string &searchWord, Node* node, int i, int numWordsMatched) {
        if (i == searchWord.length()) return node -> checkEnd() && numWordsMatched >= 1;
        if (!node -> containsLink(searchWord[i])) return false;

        Node* nextNode = node -> getLink(searchWord[i]);

        if (nextNode -> checkEnd()) {
            if (DFS(searchWord, root, i + 1, numWordsMatched + 1)) return true;
        }
        return DFS(searchWord, nextNode, i + 1, numWordsMatched);
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });

        Trie* prefixTree = new Trie();
        vector<string> concatStrings;

        for (int i = 0; i < words.size(); i++) {
            if (prefixTree -> checkConcat(words[i])) concatStrings.push_back(words[i]);
            else prefixTree -> insertWord(words[i]);
        }
        return concatStrings;
    }
};

/*
Question Link: https://leetcode.com/problems/concatenated-words/description/
Author: M.R.Naganathan
*/
