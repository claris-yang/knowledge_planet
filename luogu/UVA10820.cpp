//
// Created by yangtao on 20-8-25.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 50005;
int ans[N];
int n;
void phi(int n) {
    for(int i = 2; i <= n; i++) ans[i] = 0 ;
    ans[1] = 1;
    for(int i = 2; i <= n ; i ++) {
        if(!ans[i]) {
            for(int j = i ; j <=n; j+=i) {
                if(!ans[j]) ans[j] = j;
                ans[j] = ans[j] / i * (i - 1);
            }
        }
    }
    ll p = 1;
    for(int  i = 2; i <= n; i++) {
        p += (ans[i] << 1);
        ans[i] = p;
    }
}
int main() {
    phi(N);
    while(scanf("%d", &n) != EOF && n != 0 ) {
        printf("%d\n", ans[n]);
    }
    return 0;
}