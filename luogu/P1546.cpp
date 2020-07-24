//
// Created by yangtao on 19-10-23.
//

#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 105
int adj[MAXN][MAXN];
int cost[MAXN], visit[MAXN];
int n , idx;
int prim() {
    memset(cost, 0x3f, sizeof(cost));
    cost[1] = 0;
    int res = 0;
    for(int i = 0 ; i < n; i++ ) {
        idx = 0;
        for(int j = 1; j <=n; j++) {
            if (visit[j] == 0 && cost[j] < cost[idx]) {
                idx = j;
            }
        }
        visit[idx]=1;
        res+=cost[idx];
        for(int j = 1; j <=n; j++) {
            if(visit[j] == 0 && cost[j] > adj[idx][j]) {
                cost[j] = adj[idx][j];
            }
        }
    }
    return res;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=n; j++) {
            cin >> adj[i][j];
        }
    }

    cout << prim() << endl;
    return 0;

}