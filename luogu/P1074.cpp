//
// Created by yangtao on 20-6-19.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10;
int row[N][N], col[N][N], rect[N][N];
int a[N][N];
int n , ans = -1, score;
int m[100][4];
struct Node {
    int row, cnt;
    bool operator<(const Node &d) {
        return cnt < d.cnt;
    }
}node[N];
int idx;
int point(int x, int y) {
    if(x == 1 || y == 1 || x == 9 || y == 9) return 6;
    if(x == 2 || y == 2 || x == 8 || y == 8) return 7;
    if(x == 3 || y == 3 || x == 7 || y == 7) return 8;
    if(x == 4 || y == 4 || x == 6 || y == 6) return 9;
    return 10;
}

int cal(int i, int j) {
    if(i<=3)
    {
        if(j<=3)        return 1;
        else if(j<=6)   return 2;
        else            return 3;
    }
    else if(i<=6)
    {
        if(j<=3)        return 4;
        else if(j<=6)    return 5;
        else            return 6;
    }
    else
    {
        if(j<=3)        return 7;
        else if(j<=6)   return 8;
        else            return 9;
    }
}

void dfs(int x, int c) {

    if(x == idx) {
        ans = max(ans, c);
        return ;
    }

    for(int i = 1; i <= 9; i++) {
        if( !row[m[x][0]][i] && !col[m[x][1]][i] && !rect[m[x][3]][i]) {
            row[m[x][0]][i] = 1;
            col[m[x][1]][i] = 1;
            rect[m[x][3]][i] = 1;
            dfs(x + 1, c + m[x][2] * i);
            row[m[x][0]][i] = 0;
            col[m[x][1]][i] = 0;
            rect[m[x][3]][i] = 0;
        }
    }
}

int main() {

    n = 9;
    for(int i = 1; i <= n; i++ ) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            node[i].row = i;
            if(a[i][j] > 0) {
                row[i][a[i][j]] = col[j][a[i][j]] = rect[cal(i, j)][a[i][j]] = 1;
                score += a[i][j] * point(i, j);
            } else {
                node[i].cnt++;
            }
        }
    }
    sort( node + 1, node + n + 1);

    for(int i = 1; i <= 9 ; i++) {
        for(int j = 1; j <= 9; j++) {
            if( a[node[i].row][j] == 0 ) {
                m[idx][0] = node[i].row;
                m[idx][1] = j;
                m[idx][2] = point(node[i].row, j);
                m[idx++][3] = cal(node[i].row, j);
            }
        }
    }

    dfs(0, score);
    cout << ans << endl;

    return 0;

}
