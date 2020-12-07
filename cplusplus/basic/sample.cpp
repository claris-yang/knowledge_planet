//
// Created by yangtao on 20-11-12.
//

#include <iostream>
#include <stack>
using namespace std;
char t;
stack<int> s;
int n, cnt;
int main() {
    cin >> n;
    n *= 2;
    for(int i = 0 ; i < n; i++) {
        cin >> t;
        if(t == '(') {
            s.push(++cnt);
        } else {
            cout << s.top() << " ";
            s.pop();
        }
    }
    return 0;
}