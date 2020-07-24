//
// Created by yangtao on 20-5-12.
//


#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n;
int state3 = 1;
int cnt = 20;
stack<int> state2;
vector<int> state1;
void dfs() {
    if(!cnt) return ;
    if( state1.size() == n) {
        cnt--;
        for(auto v : state1) cout << v;
        cout << endl;
        return ;
    }
    if(state2.size()) {
        state1.push_back(state2.top()) ;
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