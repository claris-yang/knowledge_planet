//
// Created by yangtao on 20-6-12.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10005;
int n;
int a[11], res[N][11];
bool flag = false;
int cnt;
void dfs(int v, int p) {
    if( v > n || p > 11 ) return;
    if( v == n && p == 11 ) {
        for(int i = 1; i <= 10; i++) {
            res[cnt][i] = a[i];
        }
        cnt++;
        return ;
    }

    for(int i = 1; i <= 3; i++) {
        if( n - v >= i ) {
            a[p] = i;
            dfs(v + i, p + 1);
        }
    }
}
int main() {
    cin >> n;
    dfs(0, 1);
    if(!cnt) cout << 0;
    else {
        cout << cnt << endl;
        for(int i = 0; i < cnt; i++) {
            for(int j = 1; j <= 10; j++) {
                printf("%d ", res[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}