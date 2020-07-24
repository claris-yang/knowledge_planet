//
// Created by yangtao on 19-8-5.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 20;
int a[N][N];
int row[N][N], col[N][N], r[N][N];
int cal(int x, int y) {
    return (x - 1) / 3 * 3 + (y - 1) / 3 + 1;
}
void dfs(int x, int y) {

    if(x > 9 || y > 9) {
        for(int i = 1; i <= 9 ; i++) {
            for(int j = 1;j <= 9; j++) {
                printf("%d ", a[i][j]);
            }
            cout << endl;
        }
        return;
    }

    if(!a[x][y]) {
        for(int i = 1; i <= 9; i ++) {
            if( row[x][i] || col[y][i] || r[cal(x, y)][i]) continue;
            row[x][i] = col[y][i] = r[cal(x, y)][i] = 1;
            a[x][y] = i;
            if(y == 9) {
                dfs(x + 1, 1);
            } else {
                dfs(x, y + 1);
            }
            a[x][y] = 0;
            row[x][i] = col[y][i] = r[cal(x, y)][i] = 0;
        }
    } else {
        if(y == 9) {
            dfs(x + 1, 1);
        } else {
            dfs(x, y + 1);
        }
    }
}

int main() {
    for(int i = 1;i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            scanf("%d", &a[i][j]);
            row[i][a[i][j]] = col[j][a[i][j]] = r[cal(i,j)][a[i][j]] = 1;
        }
    }
    dfs(1, 1);
    return 0;
}