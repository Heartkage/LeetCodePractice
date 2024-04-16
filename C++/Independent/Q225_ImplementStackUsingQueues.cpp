#include<iostream>
#include<queue>

using namespace std;

class MyStack {
    queue<int> q1;
    int count;
public:
    MyStack() {
        count = 0;
    }
    
    void push(int x) {
        q1.push(x);
        count++;
        for(int i = 1; i < count; i++){
            int current = top();
            q1.pop();
            q1.push(current);
        }
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        count--;
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};


int main(void){
    MyStack *stack = new MyStack();
    stack->push(1);
    stack->push(2);
    stack->push(3);
    cout << stack->top() << endl;
    cout << stack->pop() << endl;
    cout << stack->top() << endl;
    cout << stack->pop() << endl;
    cout << stack->top() << endl;
    cout << stack->pop() << endl;
    if(stack->empty())
        cout << "True" << endl;
    else
        cout << "False" << endl;
    stack->push(5);
    cout << stack->top() << endl;
    cout << stack->pop() << endl;
    if(stack->empty())
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}