//
// Created by yangtao on 19-10-25.
//
#include <iostream>
using namespace std;
int dp[50005];
int a[50005];
int main() {

    int c, h;
    cin >> c >> h;
    for (int i = 1; i <=h ; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= h; i++) {
        for(int j = c ; j >= a[i]; j--) {
            dp[j] = max(dp[j], dp[j-a[i]] + a[i] );
        }
    }

    cout << dp[c] << endl;
    return 0;
}
