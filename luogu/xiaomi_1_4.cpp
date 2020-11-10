//
// Created by yangtao on 20-10-23.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e5 + 5;
typedef unsigned  long long ull;
int n, m;
priority_queue<int> q;
struct Node {
    int val, d;
    bool operator<(const Node &node) const {
        if(d == node.d) {
            return val > node.val;
        }
        return d > node.d;
    }
}a[N];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].val, &a[i].d);
        m = max(m, a[i].d);
    }
    sort(a + 1, a + n + 1);
    ull cnt = 0;
    int tot = 1;
    for(int i = m; i >= 1; i--) {
        if(tot > n) break;
        if(!q.empty() ){
            if( a[tot].d < i ) {
                cnt += q.top();
                q.pop();
            } else if (q.top() >= a[tot].val) {
                cnt += q.top();
                q.pop();
            }  else {
                cnt += a[tot++].val;
            }
        }  else if (a[tot].d >= i ){
            cnt += a[tot++].val;
        }

        // 把可以的券放到队列里面
        while( a[tot].d >= i ){
            q.push(a[tot++].val);
        }
    }
    printf("%lld", cnt);
    return 0;
}
