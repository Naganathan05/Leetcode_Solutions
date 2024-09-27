/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Node {
private:
    Node* links[2];
    bool isEnd;
public:
    Node() {
        isEnd = false;
        for(int i = 0; i <= 1; i++) links[i] = NULL;
    }

    bool containsLink(int bit){
        return links[bit] != NULL;
    }

    void putLink(int bit, Node* node){
        links[bit] = node;
        return;
    }

    Node* getLink(int bit){
        return links[bit];
    }

    void setEnd(){
        isEnd = true;
        return;
    }

    bool checkEnd(){
        return isEnd;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insertNumber(int num){
        Node* currNode = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(!(currNode -> containsLink(bit))) currNode -> putLink(bit, new Node());
            currNode = currNode -> getLink(bit);
        }
        currNode -> setEnd();
        return;
    }

    int maximumXOR(int num){
        Node* currNode = root;
        int xorVal = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(currNode -> containsLink(!bit)){
                currNode = currNode -> getLink(!bit);
                xorVal += (pow(2, i));
            }
            else currNode = currNode -> getLink(bit);
        }
        return xorVal;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* prefixTree = new Trie();
        for(int num : nums) prefixTree -> insertNumber(num);

        int maxXOR = 0;
        for(int num : nums) maxXOR = max(maxXOR , (prefixTree -> maximumXOR(num)));
        return maxXOR;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
Author: M.R.Naganathan
*/
