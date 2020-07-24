//
// Created by yangtao on 20-6-8.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
map<int, int> mm;
int n, m, idx = 1;

int main() {
    while(1) {
        cin >> n;
        if(n == 0) break;
        printf("Scenario #%d\n", idx++);
        vector<queue<int> > v(n + 1);
        //queue<int> q;
        //v.push_back(q);
        for(int i = 1 ; i <= n; i++) {
            scanf("%d", &m);
            for(int j = 1; j <= m; j++) {
                int t;
                scanf("%d", &t);
                mm[t] = i;
            }
            //queue<int> q;
            //v.push_back(q);
        }
        string s;
        while(1) {
            cin >> s;
            if(s == "STOP") {
                printf("\n");
                break;
            } else if (s == "ENQUEUE") {
                int z;
                cin >> z;
                int d = mm[z];
                if(v[d].empty()) {
                    v[0].push(d);
                }
                v[d].push(z);
            } else {
                int t = v[0].front();
                while( v[t].empty() ) {
                    v[0].pop();
                    t = v[0].front();
                }
                cout << v[t].front()<< endl;
                v[t].pop();
            }
        }
    }
    return 0;
}