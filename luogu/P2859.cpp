//
// Created by yangtao on 20-4-28.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
using  namespace std;
const int N= 5e5 + 5;
struct Cow {
    int no;
    int begin, end;
    bool operator<(const Cow &c) const {
        return begin < c.begin;
    }
};
Cow a[N];
int c[N];
int n;
priority_queue<pair<int, int> > q;
int main() {
    cin >> n;
    for(int i = 1 ; i <= n; i++) {
        scanf("%d%d", &a[i].begin, &a[i].end);
        a[i].no = i;
    }

    sort(a + 1, a + n + 1) ;

    q.push(make_pair( -a[1].end, 1));
    c[a[1].no] = 1;

    int cnt = 1;
    for(int j = 2; j <= n; j++) {
        pair<int, int> t = q.top();
        if( (-t.first) < a[j].begin ) {
            q.pop();
            q.push(make_pair( -a[j].end, t.second));
            c[a[j].no] = t.second;
        } else {
            c[a[j].no] = ++cnt;
            q.push(make_pair( -a[j].end, cnt ));

        }
    }

    cout << cnt << endl;
    for(int i = 1; i <= n; i++) {
        printf("%d\n", c[i]);
    }

    return 0;
}