//
// Created by yangtao on 20-5-7.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e5 + 5;
struct Node {
    int val, x, y;
    bool operator<(const Node & a) const {
        return val > a.val;
    }
    Node(int val, int x, int y) : val(val), x(x), y(y){}
};
priority_queue<Node> q;
int n;
int cnt = 1;
int d1[N], d2[N];
int main() {
    cin >> n;

    for(int i = 0 ; i < n; i++ ) {
        scanf("%d", &d1[i]);
    }
    for(int i = 0 ;i < n; i++) {
        scanf("%d", &d2[i]);
    }

    q.push(Node ( d1[0] + d2[0], 0, 0 ));


    int t = d1[0] + d2[0];
    while (cnt <= n) {
        Node node = q.top();
        q.pop();
        if(t == node.val) continue;
        printf("%d ", node.val);
        q.push(Node(d1[node.x+1] + d2[node.y], node.x + 1, node.y));
        q.push(Node(d1[node.x] + d2[node.y+1], node.x, node.y + 1));
        cnt++;
    }

    return 0;
}