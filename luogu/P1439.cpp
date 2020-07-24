//
// Created by yangtao on 20-4-13.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 10005;
int f[N][N];
int a[N], b[N];
int n;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i =1; i <=n ; i++) {
        scanf("%d", &b[i]);
    }

    int res = 0 ;
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <=n ; j++) {
            f[i][j] = max(f[i-1][j], f[i][j-1]);
            if(a[i] == b[j]) {
                f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
            }
            res = max(res, f[i][j]);
        }
    }
    cout << res << endl;
    return 0;
}