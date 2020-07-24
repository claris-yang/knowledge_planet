//
// Created by yangtao on 19-8-8.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int a[105][105];
struct Node {
    int step;
    int dp;
};
bool visit[10005];
void dfs() {
    queue<Node> q;
    Node first ;
    first.dp = (1 << n) - 1;
    first.step = 0;
    q.push(first);
    while(!q.empty()) {
        Node pre = q.front();
        q.pop();
        for(int i = 1; i <= m; i++) {
            int now = pre.dp;
            for(int j = 1; j <= n ; j++) {
                if(a[i][j] == 1) {
                    if((1 << (j-1)) & now) {
                        now = (1 << (j-1)) ^ now;
                    }
                } else if(a[i][j] == -1) {
                    now = (1 << (j-1)) | now;
                }
            }

            if(visit[now] == true) {
                continue;
            }

            if(now != 0) {
                visit[now] = true;
                Node node;
                node.dp = now;
                node.step = pre.step + 1;
                q.push(node);
            } else if(now == 0 ){
                visit[0] = true;
                cout << pre.step + 1 << endl;
                return ;
            }

        }
    }

}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    memset(visit, 0, sizeof(visit));
    dfs();
    if(visit[0] == false) {
        cout << -1 << endl;
    }
    return 0;
}