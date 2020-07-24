//
// Created by yangtao on 20-5-6.
//


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 25;
char c[N][N];
int n, m, x, y;
int cnt;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
void bfs( int x, int y ) {
    queue<int> qx, qy;
    qx.push(x), qy.push(y);

    cnt = 1;
    while(!qx.empty()) {
        int xx = qx.front();
        int yy = qy.front();
        qx.pop(), qy.pop();
        for( int i = 0; i < 4; i++ ) {
            int xxx = xx + dx[i];
            int yyy = yy + dy[i];
            if( xxx > 0 && xxx <= n && yyy > 0 && yyy <=m && c[xxx][yyy] == '.' ) {
                qx.push(xxx), qy.push(yyy);
                c[xxx][yyy] = '#';
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);

}
int main() {
    while(1) {
        cin >> m >> n;
        if(n == 0 && m == 0) break;
        for(int i = 1; i <=n; i++) {
            for(int j = 1; j <=m; j++) {
                //scanf("%c", &c[i][j]);
                cin >> c[i][j];
                if(c[i][j] == '@') {
                    x = i, y = j;
                }
            }
        }
        bfs(x,y);
    }
    return 0;
}
