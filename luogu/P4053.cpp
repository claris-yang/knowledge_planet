//
// Created by yangtao on 20-6-16.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 200200;
int n;
struct Node {
    int x, y;
    bool operator<(const Node &node) const {
        return y < node.y;
    }
};
priority_queue<int> q;
Node node[N];
int main() {
    cin >> n;
    for(int i = 0 ; i < n; i++) {
        scanf("%d%d", &node[i].x, &node[i].y);
    }
    sort(node, node+n);
    q.push(node[0].x);
    int time = node[0].x;
    for(int i = 1 ;i < n; i++) {
        if( time + node[i].x > node[i].y ) {
            int t = q.top();
            if( t > node[i].x ) {
                q.pop();
                q.push(node[i].x);
                time -= t;
                time += node[i].x;
            }
        } else {
            q.push(node[i].x);
            time += node[i].x;
        }
    }
    cout << q.size() << endl;
    return 0;
}
