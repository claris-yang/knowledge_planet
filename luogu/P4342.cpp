//
// Created by yangtao on 20-7-10.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 105;
const int inf = 0x3f3f3f3f;
int n, f[N][N][2], res = -inf;
char c[N];
vector<int> list;
int main() {
    cin >> n;

    for(int i = 1; i <= 2 * n ; i++) {
        for(int j = 1; j <= 2 * n; j++) {
            f[i][j][1] = inf;
            f[i][j][0] = -inf;
        }
    }

    for(int i = 1; i <=n; i++) {
        cin >> c[i] >> f[i][i][1];
        c[i+n] = c[i];
        f[i][i][0] = f[i+n][i+n][0] = f[i+n][i+n][1] = f[i][i][1];
    }

    for(int len = 2; len <= n; len++) {
        for(int i = 1; i + len - 1 <= 2 * n; i++) {
            int j = i + len - 1;
            for(int k = i ; k + 1 <= j; k++) {
                if(c[k + 1] == 'x') {
                    f[i][j][0] = max(f[i][j][0], f[i][k][0] * f[k+1][j][0]);
                    f[i][j][0] = max(f[i][j][0], f[i][k][1] * f[k+1][j][1]);
                    f[i][j][0] = max(f[i][j][0], f[i][k][0] * f[k+1][j][1]);
                    f[i][j][0] = max(f[i][j][0], f[i][k][1] * f[k+1][j][0]);

                    f[i][j][1] = min(f[i][j][1], f[i][k][1] * f[k+1][j][0]);
                    f[i][j][1] = min(f[i][j][1], f[i][k][1] * f[k+1][j][1]);
                    f[i][j][1] = min(f[i][j][1], f[i][k][0] * f[k+1][j][1]);
                    f[i][j][1] = min(f[i][j][1], f[i][k][1] * f[k+1][j][0]);
                } else {
                    f[i][j][0] = max(f[i][j][0], f[i][k][0] + f[k+1][j][0]);

                    f[i][j][1] = min(f[i][j][1], f[i][k][1] + f[k+1][j][1]);
                }

            }
            if( len == n && f[i][i+len-1][0] > res) {
                res = f[i][i+len-1][0];

            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(f[i][i+n-1][0] == res) list.push_back(i);
    }
    cout << res << endl;
    for(int i = 0; i < list.size(); i++) cout << list[i] << " " ;
    return 0;
}
