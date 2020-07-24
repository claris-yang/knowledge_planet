//
// Created by yangtao on 19-11-5.
//

#include <iostream>
#include <deque>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 510;
typedef pair<int, int> PII;
int n,m;
int d[N][N];
char g[N][N];
deque<PII> q;
int bfs() {
    memset(d, 0x3f, sizeof(d));
    q.push_back(PII(0,0));
    d[0][0] = 0;

    int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, 1, -1};
    int ix[] = {-1,-1, 0, 0} , iy[] = {-1,0,0,-1};
    char cs[] = "\\/\\/";

    while(!q.empty()) {
        PII t = q.front();
        q.pop_front();
        int x = t.first, y = t.second;
        for(int i = 0 ; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if(xx >= 0 && yy >= 0 && xx <= n && yy <= m) {
                int w = 0;
                int j = x + ix[i], k = y + iy[i];
                if(g[j][k] != cs[i])  w = 1;
                if(d[xx][yy] > d[x][y] + w) {
                    d[xx][yy] = d[x][y] + w;
                    if(w) q.push_back(PII(xx, yy));
                    else q.push_front(PII(xx, yy));
                }
            }
        }
    }

    if(d[n][m] == 0x3f3f3f3f) return -1;
    else d[n][m];
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) scanf("%s", g[i]);
        int ans  = bfs();
        if( -1 == ans) puts("No SOLUTION");
        else printf("%d\n", ans);
    }
    return 0;
}