//
// Created by yangtao on 20-5-8.
//

#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
const int N = 100005;
stack<int> s;
int in[N], out[N];
int q, n;
bool check() {
    int i = 0, j = 0;
    for(i = 0  ; i < n; i++) {
        while( s.empty() || s.top() != out[i] ) {
            if(j < n ) s.push(in[j++]) ;
            else break;
        }
        if(s.top() != out[i] ) return false;
        s.pop();
    }
    return true;
}
int main() {
    cin >> q;
    while( q-- > 0 ) {
        cin >> n;
        for(int i =  0 ; i < n; i++) scanf("%d", &in[i]);
        for(int i =  0 ; i < n; i++) scanf("%d", &out[i]);

        bool flag = check();

        if(flag) printf("Yes\n");
        else printf("No\n");

        while(!s.empty()) s.pop();

    }
    return 0;
}
