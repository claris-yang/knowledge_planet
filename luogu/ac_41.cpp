//
// Created by yangtao on 20-5-9.
//

#include <stack>
using namespace std;
class MinStack {
public:
    stack<int> s,min;
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s.push(x);
        if(min.empty()) min.push(x);
        else if( min.top() > x) min.push(x);
        else min.push(min.top());
    }

    void pop() {
        s.pop();
        min.pop();
    }

    int top() {
        if(s.size() <=0 ) return -1;
        return s.top();
    }

    int getMin() {
        if(min.size() <= 0 ) return -1;
        return min.top();
    }
};