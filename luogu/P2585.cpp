//
// Created by yangtao on 20-9-27.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 500050;
int mmax[N][4], mmin[N][4];
char s[N];
int cnt, ans = 1;

void dfs(int root) {
    if(s[root] == '0') {
        mmin[root][0] = mmax[root][0] = 1;
        return ;
    }
    dfs(++cnt);
    if(s[root] == '1') {
        mmax[root][0] = max(mmax[root+1][1], mmax[root+1][2]) + 1;
        mmax[root][1] = max(mmax[root+1][0], mmax[root+1][2]);
        mmax[root][2] = max(mmax[root+1][0], mmax[root+1][1]);

        mmin[root][0] = min(mmin[root+1][1], mmin[root+1][2]) + 1;
        mmin[root][1] = min(mmin[root+1][0], mmin[root+1][2]);
        mmin[root][2] = min(mmin[root+1][0], mmin[root+1][1]);
    } else {
        int k = ++ cnt;
        dfs(k);
        mmax[root][0] = max(mmax[root+1][1] + mmax[k][2], mmax[root+1][2] + mmax[k][1]) + 1;
        mmax[root][1] = max(mmax[root+1][0] + mmax[k][2], mmax[root+1][2] + mmax[k][0]);
        mmax[root][2] = max(mmax[root+1][0] + mmax[k][1], mmax[root+1][1] + mmax[k][0]);

        mmin[root][0] = min(mmin[root+1][1] + mmin[k][2], mmin[root+1][2] + mmin[k][1]) + 1;
        mmin[root][1] = min(mmin[root+1][0] + mmin[k][2], mmin[root+1][2] + mmin[k][0]);
        mmin[root][2] = min(mmin[root+1][0] + mmin[k][1], mmin[root+1][1] + mmin[k][0]);
    }
    ans = max(ans, mmax[root][0]);

}

int main() {
    cin >> s + 1;
    dfs(++cnt);
    cout << ans << ' ' << min(mmin[1][0], min(mmin[1][1], mmin[1][2])) << endl;
    return 0;
}