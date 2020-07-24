//
// Created by yangtao on 19-7-19.
//

#include <iostream>
#include <algorithm>

#define MAXN 30
using namespace std;
struct Node {
    int x;
    int y;
    int val;
    bool operator<(const Node &node) const {
        return val > node.val;
    }
};

Node nodes[405];

int main() {
    int M, N , K;
    cin >> M >> N >> K;
    int val, idx = 0;
    for(int i = 0 ; i < M; i++) {
        for(int j = 0; j < N ; j++) {
            cin >> val;
            if(val > 0 ){
                Node n;
                n.x = i+1;
                n.y = j+1;
                n.val = val;
                nodes[idx++] = n;
            }
        }
    }
    sort(nodes, nodes + idx);

    int res = nodes[0].val;
    int s = nodes[0].x + 1;

    for(int i = 1; i < idx; i++) {

        if(s + nodes[i-1].x > K) {
            res -= nodes[i-1].val;
            break;
        } else if( s + nodes[i-1].x == K) {
            break;
        }

        s += abs(nodes[i].x - nodes[i-1].x) + abs(nodes[i].y - nodes[i-1].y) + 1;
        res += nodes[i].val;

        if( i == idx - 1 && s + nodes[idx-1].x > K ) {
            res -= nodes[idx-1].val;
        }

    }

    cout << res << endl;


    return 0;
}