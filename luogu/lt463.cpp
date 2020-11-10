//
// Created by yangtao on 20-10-30.
//

#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0 , 1, 0};
int islandPerimeter(vector<vector<int>>& grid) {
    if( !grid.size() ) return 0;
    int n = grid.size();
    int res = 0 ;
    for(int i = 0;  i < n; i++) {
        int m = grid[i].size();
        cout << m << endl;
        for(int j = 0 ; j < m ; j ++) {
            int cnt = 0;
            if(!grid[i][j]) continue;
            for(int k = 0 ; k < 4; k++) {
                int xx = dx[k] + i;
                int yy = dy[k] + j;
                if(xx < 0 || xx >= n || yy < 0 || yy >= m) {
                    cnt+=1;
                    continue;
                }
                if(!grid[xx][yy]) cnt += 1;
            }
            res += cnt;
        }
    }
    return res;
}

int main() {
    vector<vector<int> > a;
    a.push_back({1, 0});
    cout << islandPerimeter(a);
}