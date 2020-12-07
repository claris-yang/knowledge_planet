#include <stdio.h>

using namespace std;
const int N = 1e5 + 5;
int n, ans;
int n1, n2;
int main() {
    cin >> n;
    a[1] = n1 = n2 = 1;
    for(int i = 1; i <= n; ) {
        ans = n1 + n2;
        a[ans] = 1; // ans 是fab数， 我们把a[ans] 设置为 1
        ans = n2;
        n2 = n1;
        i = ans; // 我们把i设置fab数， 下次循环的时候判断fab数是否大于n如果大于n就结束。
    }
    return 0;
}