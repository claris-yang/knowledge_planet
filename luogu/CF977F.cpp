//
// Created by yangtao on 20-11-8.
//
//
// Created by yangtao on 2020/11/1.
//

#include<iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int N = 2e5 + 5;
int n, ans , v;
int a[N];
map<int, int> mm;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mm[a[i]] = max(mm[a[i]], mm[a[i]-1] + 1);
        if( mm[a[i]] > ans ) ans = mm[a[i]], v = a[i];
    }

////    map<int,int>::iterator it = mm.begin();
//    auto it = mm.begin();
//    for(; it != mm.end(); it++) {
//        cout << it->first << " " << it->second<< endl;
//    }
    cout << ans << endl;
    for(int i = 1; i <= n; i++) {
        if( a[i] == v - ans + 1) {
            cout << i << " ";
            ans--;
        }
    }
    return 0;
}
