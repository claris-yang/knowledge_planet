//
// Created by yangtao on 20-5-20.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 305;
char c[N][N];
int n,m;
int d[N][N];

int sx, sy, ex, ey;
struct Node {
    int x, y;
};
Node bucket[30][2];
queue<Node> q;
int xx[4] = {0, -1, 0, 1};
int yy[4] = {-1, 0, 1, 0};
void bfs() {

    q.push(Node{sx, sy});
    d[sx][sy] = 0;
    while(!q.empty()) {
        Node node = q.front();
        q.pop();

        for(int i = 0; i < 4; i++ ) {

            int dx = node.x + xx[i];
            int dy = node.y + yy[i];

            if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;

            if(c[dx][dy] == '=') {
                cout << d[node.x][node.y] + 1 << endl;
                return ;
            }

            if( c[dx][dy] == '.' && d[dx][dy] == -1 ) {
                q.push(Node{dx, dy});
                d[dx][dy] = d[node.x][node.y] + 1;
            }

            if( c[dx][dy] >= 'A' && c[dx][dy] <= 'Z' && d[dx][dy] == -1) {

                d[dx][dy] = d[node.x][node.y] + 1;

                Node t = bucket[c[dx][dy] - 'A'][0];

                int b = 0;
                if(t.x == dx && t.y == dy) {
                    b = 1;
                }

                d[bucket[c[dx][dy] - 'A'][b].x][bucket[c[dx][dy] - 'A'][b].y] = d[dx][dy];

                for(int j = 0; j < 4; j++) {

                    int dx1 = bucket[c[dx][dy] - 'A'][b].x + xx[i];
                    int dy1 = bucket[c[dx][dy] - 'A'][b].y + yy[i];

                    if(dx1 < 0 || dx1 >= n || dy1 < 0 || dy1 >= m ) continue;

                    if(c[dx1][dy1] == '=') {
                        cout << d[dx][dy] + 1 << endl;
                        return ;
                    }


                    if (c[dx1][dy1] == '.' && d[dx1][dy1] == -1) {
                        q.push(Node{dx1, dy1});
                        d[dx1][dy1] = d[dx][dy] + 1;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    memset(d, -1, sizeof(d));
    memset(bucket, -1, sizeof(bucket));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            cin >> c[i][j];
            if(c[i][j] == '@') {
                sx = i, sy = j;
            }
            if(c[i][j] == '=') {
                ex = i, ey = j;
            }
            if(c[i][j] >= 'A' && c[i][j] <= 'Z') {
                int b = 0;
                if( bucket[c[i][j] - 'A'][b].x != -1) {
                    b = 1;
                }
                bucket[c[i][j] - 'A'][b] = Node{i, j};
            }
        }
    }

    bfs();

    return 0;

}
