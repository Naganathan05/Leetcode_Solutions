/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> freq;
        for(int i : barcodes) freq[i] += 1;
        priority_queue<pair<int, int>> maxHeap;
        for(auto i : freq) maxHeap.push({i.second, i.first});
        barcodes.clear();

        while(!maxHeap.empty()){
            auto [firstCount, firstBarcode] = maxHeap.top();
            maxHeap.pop();
            barcodes.push_back(firstBarcode);
            if(!maxHeap.empty()){
                auto [secondCount, secondBarcode] = maxHeap.top();
                maxHeap.pop();
                barcodes.push_back(secondBarcode);
                secondCount -= 1;
                if(secondCount) maxHeap.push({secondCount, secondBarcode});
            }
            firstCount -= 1;
            if(firstCount) maxHeap.push({firstCount, firstBarcode});
        }
        return barcodes;
    }
};

/*
Question Link: https://leetcode.com/problems/distant-barcodes/
Author: M.R.Naganathan
*/
