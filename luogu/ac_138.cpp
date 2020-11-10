//
// Created by yangtao on 20-10-12.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef  long long ll;
const int P = 131;
const int N = 1000005;
char s[N];
ll p[N], h[N];
int l1, l2, r1, r2;
int m, n;
int main() {
    cin >> s + 1;
    p[0] = 1;
    n = strlen(s+1);
    for(int i = 1; i <= n; i++) {
        h[i] = h[i-1] * P + (s[i] - 'a' + 1);
        p[i] = p[i-1] * P;
    }
    cin >> m;
    while(m--) {
        cin >> l1 >> r1 >> l2 >> r2;
        if( h[r1] - (h[l1-1] * p[r1 - l1 + 1]) != h[r2] - h[l2-1] * p[r2 - l2 + 1] ) {
            puts("No");
        } else {
            puts("Yes");
        }
    }
    return 0;
}