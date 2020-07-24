//
// Created by yangtao on 20-4-3.
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
char t[50];
int len;
int bucket1[10], bucket2[10];

bool check( int cur) {

    memset(bucket2, 0, sizeof(bucket2));
    for(int i = 0; i < cur; i++) {
        bucket2[t[i] - '0']++;
    }

    for(int i = 1; i <= 9; i++) {
        if(bucket2[i] > bucket1[i]) {
            return true;
        }
    }
    return false;
}

bool equalstr() {
    memset(bucket2, 0, sizeof(bucket2));
    for(int i = 0 ; i < s.length() ; i++) {
        bucket2[t[i] - '0']++;
    }
    //cout << t << endl;
    for(int i = 1; i <= 9; i++) {
        if(bucket2[i] != bucket1[i]) {
            return false;
        }
    }
    //cout << t << endl;
    return true;
}

// 1 代表当前dfs的位置, 2 代表前一个数是多少, 3 代表前缀是否相等, 4 代表是否前缀0
int dfs(int cur_pos, int pre_num , bool equal_pre, bool pre_zero) {
    cout << t << endl;
    if(check( cur_pos)) return 0;
    if(cur_pos == len ) {
        if (equalstr()) return 1;
        else return 0;
    }

    if(dp[cur_pos][pre_num][equal_pre][pre_zero] != -1) return dp[cur_pos][pre_num][equal_pre][pre_zero];

    int v = 9;
    if(equal_pre) v = s[cur_pos] - '0';

    int ans = 0;
    for(int i = 0; i <= v; i++) {
        t[cur_pos] = i + '0';
        if(pre_zero) {
            if( i == 0 ) ans += dfs(cur_pos+1, i , equal_pre && (i == v), 1) ;
            else ans += dfs(cur_pos+1, i, equal_pre && (i == v) , 0);
        } else  {
            ans += dfs(cur_pos + 1, i, equal_pre && (i == v) , 0);
        }
        t[cur_pos] = 0;
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

int main() {
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        bucket1[s[i] - '0']++;
    }
    cout << slove(s) - 1;
    return 0;
}