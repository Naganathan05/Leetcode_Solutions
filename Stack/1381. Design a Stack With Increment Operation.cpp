/*-----------------------
  Time Complexity: O(k)
  Space Complexity: O(n)
--------------------------*/

class CustomStack {
public:
    vector<int> stack;
    int top;

    CustomStack(int maxSize) {
        stack.resize(maxSize, -1);
        top = -1;
    }
    
    void push(int x) {
        if(top + 1 >= stack.size()) return;
        top += 1;
        stack[top] = x;
    }
    
    int pop() {
        if(top == -1) return -1;
        int delEle = stack[top];
        top -= 1;
        return delEle;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i <= min(top, k - 1); i++) {
            stack[i] += val;
        }
    }
};

/*
Question Link: https://leetcode.com/problems/design-a-stack-with-increment-operation/
Author: M.R.Naganathan
*/
