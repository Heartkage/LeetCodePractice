#include<iostream>
#include<stack>

using namespace std;

class MyQueue {
    stack<int> s1;
    stack<int> s2;

    void swapStack(bool moveFirstStack){
        if(moveFirstStack){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        else{
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }

public:
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        swapStack(true);
        int ans = s2.top();
        s2.pop();
        swapStack(false);
        return ans;
    }
    
    int peek() {
        swapStack(true);
        int ans = s2.top();
        swapStack(false);
        return ans;
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main(void){
    MyQueue q = new MyQueue();
    return 0;
}