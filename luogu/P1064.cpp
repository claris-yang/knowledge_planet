//
// Created by yangtao on 19-11-18.
//

#include <vector>
#include <iostream>
using namespace std;
const int N = 105;
vector<int> adj[N];
int n, m;
int v[N], p[N], q[N];
int dp[32005];
int main() {
    cin >> n >> m;
    for(int i = 1 ;i <= m ; i++) {
        cin >> v[i] >> p[i] >> q[i];
        p[i] = p[i] * v[i];
        if(q[i])
            adj[q[i]].push_back(i);
    }


    int ans  = 0;
    for(int i = 1; i <=m ; i++) {
        for(int j = n ; j >= v[i]; j--) {
            if( q[i] == 0 ) {

                dp[j] = max(dp[j], dp[j-v[i]] + p[i] );

                if(adj[i].size()>0 ) {
                    int c1 = adj[i][0];
                    if(j >= v[i] + v[c1])
                    dp[j] = max(dp[j], dp[j-v[i]-v[c1]] + p[i]  + p[c1] );
                }

                if(adj[i].size() > 1) {
                    int c2 = adj[i][1];
                    if(j >= v[i] + v[c2])
                        dp[j] = max(dp[j], dp[j-v[i]-v[c2]] + p[i]  + p[c2] );
                }

                if(adj[i].size() > 1) {
                    int c1 = adj[i][0];
                    int c2 = adj[i][1];
                    if(j >= v[i] + v[c1] + v[c2])
                        dp[j] = max(dp[j], dp[j-v[i]-v[c1]-v[c2]] + p[i]  + p[c1]  + p[c2] );
                }

                ans = max(ans, dp[j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}