class MyQueue {
public:
    stack<int> queue1;
    stack<int> queue2;
    MyQueue() {

    }
    
    void push(int x) {
        this->queue1.push(x);
    }
    
    int pop() {
        while(!queue1.empty()){
            this->queue2.push(queue1.top());
            this->queue1.pop();
        }
        int ele = this->queue2.top();
        this->queue2.pop();
        while(!queue2.empty()){
            this->queue1.push(this->queue2.top());
            this->queue2.pop();
        }
        return ele;
    }
    
    int peek() {
        while(!queue1.empty()){
            this->queue2.push(this->queue1.top());
            this->queue1.pop();
        }
        int ele = this->queue2.top();
        while(!queue2.empty()){
            this->queue1.push(this->queue2.top());
            this->queue2.pop();
        }
        return ele;
    }
    
    bool empty() {
        int size = 0;
        while(!queue1.empty()){
            size += 1;
            this->queue2.push(queue1.top());
            this->queue1.pop();
        }
        while(!queue2.empty()){
            this->queue1.push(this->queue2.top());
            this->queue2.pop();
        }
        return size == 0;
    }
};

/*
Question Link: https://leetcode.com/problems/implement-queue-using-stacks/
Author: M.R.Naganathan
*/
