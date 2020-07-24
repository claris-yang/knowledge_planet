//
// Created by yangtao on 19-9-12.
//

#include <iostream>
#include <cstdio>

using namespace std;
int n;
int mapper[35][35];
int color[35][35];
int dx[] = {0,-1,0,1,};
int dy[] = {-1, 0, 1, 0};
void dfs(int x, int y) {
    for(int i =0; i < 4; i++) {
        int xx = dx[i] + x;
        int yy = dy[i] + y;
        if(xx < 0 || yy < 0 || xx > n + 1 || yy > n + 1)
            continue;
        if( mapper[xx][yy] == 2 ) {
            mapper[xx][yy] = 0;
            dfs(xx, yy);
        }
    }

}
int main() {
    cin >> n;
    for(int i = 1; i <= n ; i++) {
        for(int j = 1; j <=n ; j++) {
            cin >> mapper[i][j];
        }
    }

    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j <=n+1 ; j++) {
            if(mapper[i][j] == 0) {
                mapper[i][j] = 2;
            }
        }
    }


    dfs(0,0);
    for(int i = 1; i <= n ; i++) {
        for(int j = 1; j <=n ; j++) {
            printf("%-2d", mapper[i][j]);
        }
        cout << endl;
    }

    return 0;
}