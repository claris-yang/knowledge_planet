//
// Created by yangtao on 19-11-1.
//

#include <iostream>
using namespace std;
long long n, m, a, b;
int main() {
    cin >> n >> m >> a >> b;
    if(n / a <= 1 && m / b <= 1) {
        cout << 1 << endl;
        return 0;
    }
    if(n / a <= 1) {
        cout << m / b << endl;
        return 0;
    }
    if(m / b <= 1) {
        cout << n / a << endl;
        return 0;
    }
    cout << (n/a)*(m/b) << endl;
    return 0;
}