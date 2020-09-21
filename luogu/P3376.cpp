//
// Created by yangtao on 20-9-16.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int h[N], e[N], ne[N],  now[N];
ll d[N], w[N];
int idx, n, m, s, t;
void add(int u, int v, ll val) {
    e[idx] = v, ne[idx] = h[u], w[idx] = val, h[u] = idx++;
}

ll dfs(int s, ll sum ) {
    if(s == t) return sum;
    ll k, res = 0;
    for(int i = now[s]; ~i  && sum ; i = ne[i]) {
        now[s] = i;
        int v = e[i];
        if(w[i] > 0 && (d[s] + 1 == d[v] )) {
            k = dfs(v, min(sum, w[i]));
            if(k == 0) d[v] = INF;
            w[i] -= k;
            w[i^1] += k;
            res += k;
            sum -= k;
        }
    }
    return res;
}

bool bfs(int s) {
    for(int i = 0; i <= n; i++) d[i] = INF;
    queue<int> q;
    q.push(s);
    d[s] = 0;
    now[s] = h[s];
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if( w[i] && d[v] == INF) {
                q.push(v);
                now[v] = h[v];
                d[v] = d[u] + 1;
                if(v == t) return true;
            }
        }
    }

    return false;

}

int main() {
    memset(h, -1, sizeof(h));
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i = 1; i <= m; i++) {
        int x, y, val;
        scanf("%d%d%d", &x, &y, &val);
        add(x, y, val);
        add(y, x, 0);
    }
    ll ans = 0;
    while(bfs(s)) {
        ans += dfs(s, INF);
    }
    cout << ans;
    return 0;
}
