//
// Created by yangtao on 19-11-27.
//

#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
const int N = 5004;
const int inf = 0x3f3f3f3f;
int x[N], y[N];
int n;
bool vis[N];
double cost[N];

double dis(int n1, int n2) {
    // 踩坑系列 这里的dx, dy不能定义成int类型
    double dx = x[n1] - x[n2];
    double dy = y[n1] - y[n2];
    return sqrt(dx * dx + dy * dy);
}

double prim() {
    double res = 0 ;

    cost[1] = 0;

    for(int i = 0; i < n; i++) {
        int idx = 0;
        for(int j = 1; j <= n; j++) {
            if(vis[j] == false && cost[j] < cost[idx]) {
                idx = j;
            }
        }

        vis[idx] = true;
        res += cost[idx];

        for(int j = 1; j <= n; j++) {
            double d = dis(idx,  j);
            if(vis[j] == false && d < cost[j]) {
                cost[j] = d;
            }
        }
    }

    return res;
}

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }


    for(int i = 1; i <=n ;i++) {
        for(int j = i; j <= n ; j++) {
            adj[j][i] = adj[i][j] = dis(i, j);
        }
    }

    // 初始化cost数组, double类型初始化最大值不能使用 0x3f进行初始化
    for(int i = 0;  i <= n; i++) cost[i] = inf;

    printf("%.2lf", prim());

    return 0;
}