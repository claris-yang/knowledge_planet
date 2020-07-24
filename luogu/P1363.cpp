//
// Created by yangtao on 19-10-8.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int dx[] = {1,-1,1,-1};
int dy[] = {-1, 1, -1, 1};
char d1[1505][1505];
int  d2[1505][1505];
int n,m;
string res = "No";
void dfs(int x, int y, int c) {
    if( x < 0 ) {
        x += n;
    }

    if(y < 0) {
        y += m;
    }

    if( d1[x][y] == '#' ) {
        return ;
    }

    if( d2[x][y] != -1 && d2[x][y]  < c - 1 ) {
        cout << c << " " << d2[x][y] << endl;
        res = "Yes";
        return ;
    }

    if( d2[x][y] != -1 && d2[x][y] == c - 1 ) {
        return ;
    }

    d2[x][y] = c;
    for(int i = 0 ;i < 4; i ++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        dfs(xx % n, yy % m, c+1);
    }
}

int main() {
    while(cin >> n >> m) {
        int x1 , y1;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0; j < m; j++) {
                cin >> d1[i][j];
                if(d1[i][j] == 'S') {
                    x1 = i;
                    y1 = j;
                }
            }
        }
        memset(d2, -1, sizeof(d2));
        dfs(x1, y1, 1);
        cout << res << endl;
    }


    return 0;
}