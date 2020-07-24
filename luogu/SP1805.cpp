//
// Created by yangtao on 20-4-29.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
using namespace std;
const int N = 100005;
typedef long long ll;
// s 保存的高度, w保存宽度
stack<ll> s, w;
ll h[N];
ll n;
ll res;
int main() {
    while(1) {
        cin >> n;

        if(!n) break;

        for(int i = 0 ;i < n; i++) {
            scanf("%lld", &h[i]);
        }


        h[n] = 0;
        s.push(h[0]), w.push(1);

        for(int i = 1 ; i <= n; i++) {
            if( s.top() <= h[i]) {
                s.push(h[i]), w.push(1);
            } else {
                ll width = 0;
                while( !s.empty() && s.top() > h[i] ) {
                    width += w.top();
                    res = max(res, s.top() * width);
                    s.pop(), w.pop();
                }
                w.push(width + 1), s.push(h[i]);
            }
        }

        printf("%lld\n", res);
    }

    return 0;
}