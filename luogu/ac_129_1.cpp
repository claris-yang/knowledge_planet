//
// Created by yangtao on 20-7-16.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
stack<int> state2;
vector<int> state1;
int state3 = 1;
int cnt, n;
void dfs() {
    if(cnt == 20) exit(0);
    if( state1.size() == n ) {
        for(auto a : state1 ) {
            cout << a;
        }
        cout << endl;
        cnt++;
        return ;
    }

    if(state2.size()) {
        state1.push_back(state2.top());
        state2.pop();
        dfs();
        state2.push(state1.back());
        state1.pop_back();
    }

    if(state3 <= n) {
        state2.push(state3);
        state3++;
        dfs();
        state3--;
        state2.pop();
    }

}
int main() {
    cin >> n;
    dfs();
    return 0;
}

