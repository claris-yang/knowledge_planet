//
// Created by yangtao on 20-11-11.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
typedef  long long ll;
const int N = 1e5 +5;
set<ll> s;
ll a[N];
int n, k, cnt;
/*
 *
集合中的任意一个数，它乘以 k 之后的数都不在这个集合内
 根据这句话我们可以得出一个结论如果这个数字不能被k整除
 这个数字一定不能通过一个整数×k得到。这么这个数字符合要求。 所以这数字满足。
 否则那么这个数字就是可以整除k， 但是它除以k以后这个数字不再集合里面 。 这个数字就一定也满足条件。
 而且原因2，所以我们一定要排序
 * */
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++) {
        if( a[i] % k != 0 || s.count( a[i] / k ) == 0 ) s.insert(a[i]);
    }
    cout << s.size();


    char s[50];
    cin >> n >> s;
    for(int i = 0; i < 2 *n ; i++) {
        cout << s[i] << endl;
    }
    return 0;

}