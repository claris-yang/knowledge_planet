//
// Created by yangtao on 20-6-19.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 12;
const int c = 9;
int a[N][N], row[N][N], col[N][N], rec[N][N];
struct Node {
    int row, cnt;
    bool operator<(const Node d) const {
        return cnt < d.cnt;
    }
}node[N];
struct PI {
    int x, y, rec, sc;
}pi[100];
int point(int x, int y) {
    if(x == 1 || y == 1 || x == 9 || y == 9) return 6;
    if(x == 2 || y == 2 || x == 8 || y == 8) return 7;
    if(x == 3 || y == 3 || x == 7 || y == 7) return 8;
    if(x == 4 || y == 4 || x == 6 || y == 6) return 9;
    return 10;
}
int res = -1, score, idx;
int cal(int i, int j) {
    return (i - 1) / 3 * 3 + (j - 1) / 3 + 1;
}
void dfs(int x, int sc) {
    if(x == idx) {
        res = max(res, sc);
        return ;
    }
    for(int i = 1; i <= c; i++) {
        if( !row[pi[x].x][i] && !col[pi[x].y][i] && !rec[pi[x].rec][i]) {
            row[pi[x].x][i] = col[pi[x].y][i] = rec[pi[x].rec][i] = 1;
            dfs(x + 1, sc +  i * pi[x].sc);
            row[pi[x].x][i] = col[pi[x].y][i] = rec[pi[x].rec][i] = 0;
        }
    }
}
int main() {
    for(int i = 1; i <= c; i++)  {
        node[i].row = i;
        for(int j = 1; j <= c; j++) {
            scanf("%d", &a[i][j]);
            if(a[i][j]) {
                row[i][a[i][j]] = col[j][a[i][j]] = rec[cal(i, j)][a[i][j]] = 1;
                score += point(i, j) * a[i][j];
            } else {
                node[i].cnt++;
            }
        }
    }
    sort(node + 1, node + c + 1);
    for(int i = 1; i <= c; i++) {
        for(int j = 1; j <= c; j++) {
            if( !a[node[i].row][j] ) {
                pi[idx].x = node[i].row;
                pi[idx].y = j;
                pi[idx].rec = cal(node[i].row, j);
                pi[idx++].sc = point(node[i].row, j);
            }
        }
    }
    dfs(0, score);
    cout << res << endl;
    return 0;
}