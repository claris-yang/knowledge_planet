//
// Created by yangtao on 19-8-5.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 30;
int a[N], col[N], d1[N], d2[N];
int n, cnt;
void dfs(int x ) {
    if(x == n + 1) {
        cnt++;
        if(cnt <= 3) {
            for(int i = 1; i <= n; i++) {
                printf("%d ", a[i]);
            }
            cout << endl;
        }
        return ;
    }
    for(int i = 1; i <= n; i++) {
        if( col[i] || d1[i-x+n] || d2[i+x]) continue;
        col[i] = d1[i-x+n] = d2[i+x] = 1;
        a[x] = i;
        dfs(x + 1);
        col[i] = d1[i-x+n] = d2[i+x] = 0;
    }
}
int main() {
    cin >> n;
    dfs(1);
    cout << cnt << endl;
    return 0;
}