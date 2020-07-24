//
// Created by yangtao on 19-11-25.
//

#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 155;
double d[N][N], d1[N];
int z[2][N];
int n;
double m1, m2 = inf;

void floyd() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <=n ; i++) {
            for(int j = 1; j <=n ;j++) {
                if(d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}

double dis(int x, int y) {
    int dx = z[0][x] - z[0][y];
    int dy = z[1][x] - z[1][y];
    return sqrt(dx * dx + dy * dy);
}

int main() {
    memset(d, 0x3f, sizeof( d) );
    cin >> n;
    for(int i = 1; i <=n ; i++) {
        scanf("%d%d", &z[0][i], &z[1][i]);
    }


    char t;
    for(int i = 1  ; i <= n; i++ ) {
        for(int j = 1; j <= n ; j++) {
            cin >> t;
            if (i == j) {
                d[i][j] = 0;
            } else if(t == '1') {
                d[i][j] = dis(i, j);
            } else  {
                d[i][j] = inf;
            }
        }
    }

    floyd();

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j<=n ; j++) {
            if(d[i][j] != inf) d1[i] = max(d1[i], d[i][j]); // 找到从i出发最长一条路径记录在d1[i]中
            m1 = max(m1, d1[i]); // 找到牧场里最长的一条路径
        }
    }

    for (int i = 0; i <= n ; ++i) {
        for (int j = 0; j <= n; ++j) {
            if(d[i][j] ==  inf) {
                m2 = min(m2, d1[i] + dis(i, j) + d1[j]);
            }
        }
    }

    printf("%.6f", max(m1, m2));

    return 0;
}
