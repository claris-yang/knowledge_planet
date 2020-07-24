//
// Created by yangtao on 19-10-17.
//

#include <iostream>
using namespace std;

int map[10][10];
int n,m, t;
int sx, sy, fx, fy;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
void dfs (int x, int y, int num) {
    if(map[x][y] == -1)
        return ;
    if(x < 1 || x > n || y < 1 || y > m) {
        return ;
    }
    if(x == fx && y == fy) {
        map[fx][fy]++;
        return;
    }
    if( map[x][y] > 0 )
        return;

    for(int i = 0 ;i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        map[x][y] = num ;
        dfs(xx, yy, num + 1);
        map[x][y] = 0;
    }
}
int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for(int i = 0 ;i < t; i++) {
        int x,y;
        cin >> x >> y;
        map[x][y] = -1;
    }
    dfs(sx, sy, 1);

    cout << (map[fx][fy] == -1 ? 0 : map[fx][fy]);

    return 0;
}