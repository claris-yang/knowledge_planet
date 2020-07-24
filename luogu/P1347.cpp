//
// Created by yangtao on 20-7-17.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
const int N = 2005;
set<int> s;
int n, m, idx, cnt;
int h[N], e[N], ne[N], ru[N], ru1[N];
struct Node {
    int v, val;
};
void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

void top(int no) {
    queue<Node> q;
    queue<int> result;
    int sum = 0, ans = 0;
    for(int i = 1; i <= 26; i++ ) {
        if(!ru[i] && s.count(i)) {
            q.push({i, 1});
            result.push(i);
            sum++;
        }
    }
    while(q.size()) {
        Node node = q.front();
        q.pop();
        int u = node.v;
        int val = node.val;
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            ru[v]--;
            if(!ru[v]) {
                sum++;
                result.push(v);
                q.push({v, val + 1});
                ans = max(ans, val + 1);
            }
        }
    }
    if(ans == n) {
        printf("Sorted sequence determined after %d relations: ", no);
        while(result.size()) {
            cout << char(result.front() + 'A' - 1);
            result.pop();
        }
        cout << ".";
        exit(0);
    }
    if(sum < cnt) {
        printf("Inconsistency found after %d relations.", no);
        exit(0);
    }
}
int main() {
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    for(int i = 1; i <= m; i++) {
        string a;
        cin >> a;
        int u = a[0] - 'A' + 1, v = a[2] - 'A' + 1;
        add(u, v);
        s.insert(u);
        s.insert(v);
        cnt = s.size();
        ru1[v]++;
        memcpy(ru, ru1, sizeof(ru1));
        top(i);
    }
    printf("Sorted sequence cannot be determined.");
    return 0;
}