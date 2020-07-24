//
// Created by yangtao on 20-6-1.
//

/**
 * 这个思路好啊
 * 首先二分答案，即：二分最大平均值。

我们将a全部减去mid，问题转化为判断是否存在一个长度在s~t范围内的区间它的和为正，如果有说明还有更大的平均值。

用前缀和和单调队列维护。

然后用单调队列求出sum[i]-min(sum[i-t]~sum[i-s]),然后判断是否大于0即可。
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
int n, a[N], q[N];
double sum[N];
int s, t;
bool check(double x) {
    for(int i = 1; i <=n ;i++ ) {
        sum[i] = sum[i-1] + double(a[i]) - x;
    }
    sum[0] = 0;
    int head = 1, tail = 0;
    for(int i = s ; i <= n; i++) {
        while( head <= tail && sum[q[tail]] > sum[i-s] ) tail--;
        q[++tail] = i - s;
        while( head <= tail && q[head] < i - t) head++;
        if( head <= tail && sum[i] - sum[q[head]] >= 0 ) return 1;
    }
    return 0;
}

int main() {
    cin >> n >> s >> t;
    for(int i = 1 ;i <= n; i++) {
        scanf("%d", &a[i]);
    }
    double l = -1e5, r = 1e5;
    while(r - l  > 1e-5) {
        double mid = (l + r) / 2;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%.3lf\n", l);
    return 0;
}