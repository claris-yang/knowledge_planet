//
// Created by yangtao on 19-9-20.
//

#include <iostream>
using namespace std;
int main() {
    long long a, b ,c;
    cin >> a >> b >> c;

    long long avg = 0, result = 0;
    if( (a+b+c) % 3 != 0 ) {
        cout << -1 << endl;
    } else {
        long long avg = (a+b+c) / 3;
        if(a > avg) {
            result += a - avg;
        }
        if(b > avg) {
            result += b - avg;
        }
        if(c > avg) {
            result += c - avg;
        }
        cout << result << endl;
    }

    return 0;
}