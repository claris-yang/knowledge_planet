//
// Created by yangtao on 20-5-28.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
 int f[N];
int  a, b, p, cnt;
bool prime[N];
void init() {
    for(int i = 1; i <= b; i++ ) f[i] = i;
}
int find(int x) {
    if(x != f[x] ) f[x] = find(f[x]);
    return f[x];
}
void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) f[x] = f[y];
}
int main() {
    cin >> a >> b >> p;
    init();
    cnt = b - a + 1;
    for(int i = 2; i <= b; i++) {
        if(prime[i]) continue;
        if( i >= p) {
            for(int j = i + i; j <= b; j+= i) {
                if(j - i >= a && find(j - i) != find(j) ) {
                    union_set(j-i, j);
                    cnt--;
                }
                prime[j] = true;
            }
        } else {
            for(int j = i * i; j <= b; j+= i) {
                prime[j] = true;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}