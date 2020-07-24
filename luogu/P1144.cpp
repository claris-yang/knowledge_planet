//
// Created by yangtao on 19-11-25.
//

// vector mle 了, 所以试一下脸是链式链式先缀星
#include <cstdio>
#include <queue>
#include <cstring>
#define ll long long
using namespace std;
const int N = 1e7 + 5;
int n,m;
bool vis[N];
int d[N];
int b[N];
queue<int> q;
int head[N], nc[N<<2], ee[N<<2];
int idx;

void SPFA() {

    memset(d, 0x3f, sizeof(d));
    d[1] = 0 ;
    vis[1] = true;
    q.push(1);
    b[1] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;

        for(int e = head[u]; ~e; e = nc[e]) {
            int y = ee[e];
            if( d[u] + 1 < d[y]) {
                d[y] = d[u] + 1;
                b[y] = b[u];
                b[y] %= 100003;
                if(!vis[y]) {
                    vis[y] = true;
                    q.push(y);
                }
            } else if( d[u] + 1 == d[y]) {
                b[y]+=b[u];
                b[y] = b[y] % 100003;
            }
        }

    }
}


void add(int x, int y) {
    ee[idx] = y, nc[idx] = head[x], head[x] = idx++;
}

int main() {
    scanf("%d%d", &n, &m);

    memset(head, -1, sizeof(head));
    for(int i = 1;i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }

    SPFA();

    for(int i = 1; i <= n; i++)
        printf("%d\n", b[i]);

    return 0;
}