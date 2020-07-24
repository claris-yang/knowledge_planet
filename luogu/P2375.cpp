//
// Created by yangtao on 20-7-22.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
const int P = 1e9+7;
typedef long long ll;
ll cnt;
int t, n, ans[N], next[N];
char a[N];
/**
 * 思路
 * ans[i] 数组记录 i 的所有前后缀长度相等的数量
 * 如何计算这个数量呢. 位置 i 所有前后缀为, next[i], next[next[i]], next[next[next[i]]] ...
 * 所以可以通过 ans[i] = ans[next[i]] + 1
 * 求出ans[i] 以后, 我们可以通过 ans[i]求出所有不重叠的 相同前后缀.使用的方法是对于i的每一个前缀.
 * 如果 next[i], next[next[i]]... 的 2 倍 小于 n + 1 的话 就满足.
 * @return
 */
int main() {
    cin >> t;
    while(t--) {
        scanf("%s", a + 1);
        n = strlen(a + 1);
        memset(next, 0, sizeof(next));
        memset(ans, 0, sizeof(ans));
        ans[1] = 1;

        for(int i = 2, j = 0 ; i <= n; i++) {
            while(j && a[j+1] != a[i] ) j = next[j];
            if(a[j+1] == a[i]) j++;
            next[i] = j; ans[i] = ans[j] + 1;

            // 这种写法慢的原因要把所有的共同前后缀遍历一遍
            // 如果是类似 aaaaaaaaaa 这种字符串. 这样 下面的算法需要一个一个的循环到n/2次
            //int k = j;
            //while( (k << 1) > i) k = next[k];
            //cnt = (cnt * (ll) ( ans[k] + 1)) % P;
        }
        cnt = 1;

        // 下面的算法不更新next数组
        // j 停在 n / 2 的 位置
        for(int i = 2, j = 0; i <= n; i++) {
            // 在判断每个字符在不匹配的时候, 再匹配到最长的next数组
            while(j && a[j+1] != a[i]) j = next[j];
            // 如果匹配或者, 只是j++
            if( a[i] == a[j+1] ) j++;
            // 回朔到不超过 总 长度的为止
            while((j << 1) > i) j = next[j];
            cnt = (cnt * (ll) ( ans[j] + 1)) % P;
        }
        printf("%lld\n", cnt);
    }

    return 0;
}
