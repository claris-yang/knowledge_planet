//
// Created by yangtao on 20-7-16.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
const int N = 1005;
map<int, int> m;
int n, t, no, idx;
int main() {
    while(1) {
        cin >> t;
        if(!t) break;
        printf("Scenario #%d\n", ++no);
        vector<queue<int> >  q(t+1);
        for(int i = 1; i <= t; i++) {
            cin >> n;
            for(int j = 1; j <=n; j++) {
                int t1;
                scanf("%d", &t1);
                m[t1] = i;
            }
        }
        while(1) {
            string s;
            cin >> s;
            if(s == "ENQUEUE") {
                int d;
                scanf("%d", &d);
                int k = m[d];
                if( !q[k].size() ) {
                    q[0].push(k);
                }
                q[k].push(d);

            } else if (s == "DEQUEUE") {
                int k = q[0].front();
                while( !q[k].size() ) {
                    q[0].pop();
                    k = q[0].front();
                }
                printf("%d\n", q[k].front());
                q[k].pop();
            } else {
                break;
            }
        }
        cout << endl;
    }

    return 0;
}
