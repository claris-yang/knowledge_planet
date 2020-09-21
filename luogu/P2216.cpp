//
// Created by yangtao on 20-8-27.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1005;
int qmax[N], qmin[N], a[N][N];
int hmax[N][N], hmin[N][N], lmax[N][N],lmin[N][N];
int n, m, k;
int head1, tail1, head2, tail2;
int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 1 ; i <= n; i++) {
        head1 = tail1 = head2 = tail2 = qmax[1] = qmin[1] = 1;
        for(int j = 2; j <= m; j++) {
            // 最大值
            while(head1 <= tail1 && a[i][qmax[tail1]] <= a[i][j])  tail1--;
            qmax[++tail1] = j;
            while( j - qmax[head1] >= k) head1++;
            if(j >= k )hmax[i][j - k + 1] = a[i][qmax[head1]];

            // 最小值
            while( head2 <= tail2 && a[i][qmin[tail2]] >= a[i][j]) tail2--;
            qmin[++tail2] = j;
            while(j - qmin[head2] >= k) head2++;
            if (j >= k ) hmin[i][j - k + 1] = a[i][qmin[head2]];
        }
    }

    for(int i = 1; i <= m - k + 1; i++) {
        head1 = head2 = tail1 = tail2 = qmax[1] = qmin[1] = 1;
        for(int j = 2; j <= n; j++) {
            // 最大值
            while(head1 <= tail1 && hmax[qmax[tail1]][i] <= hmax[j][i])  tail1--;
            qmax[++tail1] = j;
            while( j - qmax[head1] >= k) head1++;
            if (j >= k) lmax[j-k+1][i] = hmax[qmax[head1]][i];

            // 最小值
            while(head2 <= tail2 && hmin[qmin[tail2]][i] >= hmin[j][i]) tail2--;
            qmin[++tail2] = j;
            while( j - qmin[head2] >= k) head2++;

            if(j >= k) lmin[j-k+1][i] = hmin[qmin[head2]][i];
        }
    }

    int ans = 0x3f3f3f3f;
    for(int i = 1; i <= n - k + 1; i++) {
        for(int j = 1; j <= m - k + 1; j++)
            ans = min(ans, lmax[i][j] - lmin[i][j]);
    }
    cout << ans ;
    return 0;
}
