#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class MinStack {
    stack<int> m_minStack;
    stack<int> m_myStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        m_myStack.push(x);
        if(m_minStack.empty() || x <= m_minStack.top())
            m_minStack.push(x);
    }
    
    void pop() {
        if(m_minStack.top() == m_myStack.top())
            m_minStack.pop();
        m_myStack.pop();
    }
    
    int top() {
        return m_myStack.top();
    }
    
    int getMin() {
        return m_minStack.top();
    }
};

int main(void)
{
    MinStack m;

    m.push(-2);
    m.push(0);
    m.push(-3);
    cout << m.getMin() << endl;
    m.pop();
    cout << m.top() << endl;
    cout << m.getMin() << endl;


    return 0;
}