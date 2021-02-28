#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class MinStack {
    vector<int> m_minList;
    stack<int> m_myStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        m_myStack.push(x);

        int index;
        for(index = 0; index < m_minList.size(); index++)
            if(m_minList[index] > x)
                break;
        cout << "Insert index: " << index << endl;
        
        m_minList.insert(m_minList.begin()+index, x);
    }
    
    void pop() {
        int x = top();
        cout << "Top Value: " << x << endl;
        for(int index = 0; index < m_minList.size(); index++)
        {
            if(m_minList[index] == x)
            {
                m_minList.erase(m_minList.begin() + index);
                break;
            }
        }

        m_myStack.pop();
    }
    
    int top() {
        return m_myStack.top();
    }
    
    int getMin() {
        return *(m_minList.begin());
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