//
// Created by yangtao on 19-9-20.
//

#include <iostream>
#include <cstdlib>
using namespace std;
long long res;
long long a[50005];
int main() {
    int n;
    cin >> n;
    for(int i = 0 ;i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n - 1; i++) {
        res = max(res, abs(a[i] - a[i+1]));
    }

    cout << res << endl;
    return 0;
}