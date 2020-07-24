//
// Created by yangtao on 20-2-17.
//

#include <iostream>
#include <vector>
using namespace std;
const int N = 40005;
struct Node {
    int v, w, m;
};
int f[N];
int n, v;
vector<Node> list;
int main() {
    cin >> n >> v;
    for(int i = 0  ;i < n; i++) {

        int v, w, m;
        cin >> v >> w >> m;
        for(int j = 1; j <= m; j <<= 1) {
            m -= j;
            list.push_back(Node{v , w, j});
        }
        if (m > 0) {
            list.push_back(Node{v, w, m});
        }

    }

    for(Node node : list) {
        for(int i = v; i >= node.w * node.m; i--) {
            f[i] = max(f[i], f[i-node.w * node.m] + node.v * node.m);
        }
    }
    cout<<f[v]<< endl;
    return 0;
}