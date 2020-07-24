//
// Created by yangtao on 20-7-16.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
typedef long long ll;
// s 表示单调栈 , 表示每一个竖条的高度, w 表示每一个竖条的宽度
ll s[N], w[N], p;
ll a[N];
ll n;
int main() {
    while(1) {
        cin >> n;
        if(!n) break;

        ll ans = 0;

        for(int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }

        a[n+1] = p = 0;

        for(int i = 1; i <= n + 1;  i++) {
            if( a[i] >= s[p] ) {
                s[++p] = a[i], w[p] = 1;
            } else {
                int width = 0;
                while( p >= 0 && s[p] > a[i]) {
                    width+=w[p];
                    ans = max(ans, (ll)width * s[p--]);
                }
                s[++p] = a[i], w[p] = width + 1;
            }
        }
        cout << ans << endl;
    }
    return  0;
}
