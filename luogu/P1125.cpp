//
// Created by yangtao on 20-4-30.
//

#include <iostream>
#include <cstring>
using namespace std;
const int N = 105;
int bucket[30];
int mmin = 0x3f3f3f3f, mmax;
int pmin, pmax;
char c[N];

bool isPrime(int d) {
    if(2 > d) return false;
    for(int i = 2; i * i <= d; i++) {
        if(d % i == 0 ) return false;
    }
    return true;
}
int main() {
    cin >> c;
    int ll = strlen(c);
    for(int i = 0 ;i < ll; i++) {
        bucket[c[i] - 'a']++;
    }

    for(int i = 0 ;i < 26; i++)  {
        if(bucket[i]) {
            mmax = max(mmax, bucket[i]);
            mmin = min(mmin, bucket[i]);
        }
    }

    if(isPrime(mmax - mmin)) {
        cout << "Lucky Word" << endl;
        cout << mmax - mmin << endl;
    } else {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }
    return 0;

}
