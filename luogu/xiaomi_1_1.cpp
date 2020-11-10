//
// Created by yangtao on 20-10-23.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
stack<char> ss;
int main() {
    char c;
    while( cin >> c ) {

        if( c == '(' || c == '{' || c == '[' ) {
            ss.push(c);
        }  else if (ss.empty()) {
            cout << "No" << endl;
            return 0;
        } else if ( c == ')' && ss.top() == '(' ) {
                ss.pop();
        } else if (c == ']' && ss.top() == '[' ) {
                ss.pop();
        } else if( c == '}' && ss.top() == '{' ) {
                ss.pop();
        } else {
                ss.push(c);
        }

    }

    if(ss.empty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;

}