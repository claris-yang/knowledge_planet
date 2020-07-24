//
// Created by yangtao on 20-5-9.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 1e6+6;
stack<int> s1, s2;
int f[N], s[N], p;
int n;
int main() {
    cin >> n;
    f[0] = -1e7;
    for(int i = 0 ; i < n; i++) {
        char opt;
        int x;
        cin >> opt;
        if(opt == 'I') {
            scanf("%d", &x);
            s1.push(x);
            s[s1.size()] = s[s1.size()-1] + s1.top();
            f[s1.size()] = max(s[s1.size()], f[s1.size()-1]);
        } else if ( opt == 'Q') {
            scanf("%d", &x);
            printf("%d\n", f[x]);
        } else if (opt == 'L'){
            if( s1.size() > 0 ) {
                s2.push(s1.top());
                s1.pop();
            }
        } else if (opt == 'R') {
            if( s2.size() > 0  ) {
                s1.push(s2.top());
                s2.pop();
                s[s1.size()] = s[s1.size()-1] + s1.top();
                f[s1.size()] = max(s[s1.size()], f[s1.size()-1]);
            }
        } else if ( opt == 'D' ){
            if(s1.size() > 0) {
                s1.pop();
            }
        }
    }

    return 0;
}