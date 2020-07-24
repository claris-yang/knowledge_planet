//
// Created by yangtao on 20-5-15.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n , k;
struct Node {
    int v, s;
};
queue<Node> q;

int bfs() {
    q.push(Node{n, 0});
    while(!q.empty()) {
        Node node = q.front();
        if( node.v == k) {
            return node.s;
        }
        q.pop();
        q.push(Node{node.v*2, node.s+1});
        q.push(Node{node.v+1, node.s+1});
        q.push(Node{node.v-1, node.s+1});
    }
    return 0;
}
int main( ) {
    cin >> n >> k;
    cout << bfs() << endl;
    return 0;
}

