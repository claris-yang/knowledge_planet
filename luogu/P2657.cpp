//
// Created by yangtao on 20-4-2.
//

#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 12;
int dp[N][N][2][2];
string s;
int len;

// 1 代表当前dfs的位置, 2 代表前一个数是多少, 3 代表前缀是否相等, 4 代表是否前缀0
int dfs(int cur_pos, int pre_num , bool equal_pre, bool pre_zero) {
    if(cur_pos == len) return 1;
    if(dp[cur_pos][pre_num][equal_pre][pre_zero] != -1) return dp[cur_pos][pre_num][equal_pre][pre_zero];

    int v = 9;
    if(equal_pre) v = s[cur_pos] - '0';

    int ans = 0;
    for(int i = 0; i <= v; i++) {
        if(pre_zero) {
            if( i == 0 ) ans += dfs(cur_pos+1, i , equal_pre && (i == v), 1) ;
            else ans += dfs(cur_pos+1, i, equal_pre && (i == v) , 0);
        } else if ( abs(pre_num - i) >= 2) ans += dfs(cur_pos + 1, i, equal_pre && (i == v) , 0);
    }
    // 记忆化搜索 - 下次遍历到这个结果直接使用
    return dp[cur_pos][pre_num][equal_pre][pre_zero] = ans;
}


int slove(string ss) {
    s = ss;
    len = s.length();
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, 1, 1);
}

int chk(string ss ) {
    for(int i = 1; i < ss.length(); i++) {
        if( abs(ss[i] - ss[i-1]) < 2 ) return 0;
    }
    return 1;
}

int main() {
    string l, r;
    cin >> l >> r;
    cout << slove(r) - slove(l) + chk(l);
    return 0;
}