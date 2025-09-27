/*---------------------------------------
Data Structures Used: (Priority Queue)
  Time Complexity: O(logn), O(logn)
  Space Complexity: O(n)
-----------------------------------------*/

class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {

    }

    /* 
       Idea is to maintain the first half of the sorted array in maxHeap
       Maintain second half of the sorted array in minHeap
       Either both the heaps should be of same size or
       maxHeap should have 1 element more than minHeap incase of odd sized array
    */
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        return;
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/*
Question Link: https://leetcode.com/problems/find-median-from-data-stream/
Author: M.R.Naganathan
*/
