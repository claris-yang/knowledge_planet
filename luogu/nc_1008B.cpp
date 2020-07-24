//
// Created by yangtao on 20-6-28.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int P = 131;
const int N = 1000010;
ll f[N], p[N];
char s[N];
int m;
ll cal(ll x1, ll y1) {
    return f[y1] - f[x1-1] * p[y1-x1 + 1];
}
int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    p[0] = 1;
    for(int i = 1; i <= n; i++) {
        f[i] = f[i-1] * P + (s[i] - 'a' + 1) ;
        p[i] = p[i-1] * P ;
    }
    cin >> m;
    for(int i = 0 ;i < m; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(cal(x1, y1) == cal(x2, y2) ) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}