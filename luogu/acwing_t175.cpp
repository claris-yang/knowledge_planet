//
// Created by yangtao on 19-11-5.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 1005;
int n, m;
char g[N][N];
int d[N][N];
queue<PII> q;
int dx[] = {0,-1, 0, 1}, dy[] = {-1, 0, 1, 0};
void bfs() {
    while(!q.empty()) {
        PII a = q.front();
        q.pop();
        int x = a.first, y = a.second;
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if(xx >= 0 && xx < n && yy >= 0 && yy < m && d[xx][yy] == -1) {
                q.push(PII(xx, yy));
                d[xx][yy] = d[x][y] + 1;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    memset(d, - 1, sizeof(d));
    for(int i = 0 ;i < n; i++)
        scanf("%s", g[i]);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (g[i][j] == '1') {
                d[i][j] = 0;
                q.push(PII(i, j));
            }
        }
    }

    bfs();
    for(int i = 0 ;i < n ; i ++) {
        for(int j = 0;j < m; j ++) {
            printf("%d ", d[i][j]);
        }
        puts("");
    }
    return 0;
}