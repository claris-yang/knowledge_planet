//
// Created by yangtao on 19-10-31.
//

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1000;
int n, p;
int e[N], ne[N], h[N], idx;
int size[N];
int c[N];
vector<int> level[N];
int ans = N;
int add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dfs_level(int u, int depth, int father) {
    size[u] = 1;
    for(int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if(j == father) continue;
        size[u] += dfs_level(j, depth + 1, u);
        level[depth].push_back(i);
    }
    return size[u];
}

void dfs_draw(int j, int color) {
    c[j] = color;
    for(int i = h[e[j]]; ~i; i = ne[i]) {
        if(i != (j ^ 1))
            dfs_draw(i, color);
    }

}

void dfs(int u, int s) {
    ans = min(ans, s);
    for(int i = 0 ;i < level[u].size(); i++) {
        int j = level[u][i];
        if(!c[j]) {
            dfs_draw(j, 1);
            dfs(u+1, s - size[e[j]]);
            dfs_draw(j, 0);
        }
    }
}
int main() {
    memset(h, -1, sizeof(h));
    cin >> n >> p;
    for(int i = 1; i <= p ; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs_level(1, 0, -1);
    dfs(0, n);
    cout << ans << endl;
    return 0;
}
