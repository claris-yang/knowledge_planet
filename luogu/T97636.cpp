//
// Created by yangtao on 20-10-15.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int cnt, a, b;
int main() {
    cin >> a >> b;
    int d = a - b;

    // 考虑a, b 的左右位置
    if(d < 0) {
        d = -d;
    }

    // 先把距离当偶数计算， 计算出a, b
    for(int i = 1;  i <= d / 2; i++ ) {
        cnt += i;
    }

    // 计算一个2两个同学一共消耗的体力
    cnt *= 2;

    // 如果两个同学之间距离为奇数，加上最后一步。
    if( d % 2 == 1) {
        cnt += (d + 1) / 2;
    }
    cout << cnt << endl;
    return 0;
}