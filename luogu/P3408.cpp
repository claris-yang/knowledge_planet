//
// Created by yangtao on 20-8-12.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 5e5 + 5;
typedef long long ll;
vector<ll> a[N];
ll f[N];
ll n, t, c;
ll dfs(int r) {
    if(a[r].size() == 0) return f[r];
    priority_queue<ll, vector<ll>, greater<ll> > q;
    for(int i = 0 ; i < a[r].size(); i++)
        q.push(dfs(a[r][i]));
    ll ans = 0;
    for(int i = 0; i < 1.0 * f[r] * a[r].size() / t; i++) {
        ans += q.top();
        q.pop();
    }
    return ans;
}
int main() {
    cin >> n >> t >> c;
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d%lld", &x, &f[i]);
        a[x].push_back(i);
    }
    f[0] = c;
    cout << dfs(0) << endl;
    return 0;

}
