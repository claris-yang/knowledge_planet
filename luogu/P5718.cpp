//
// Created by yangtao on 20-4-30.
//

#include <iostream>
using namespace std;
const int N = 105;
int n;
int mmin = 0x3f3f3f3f;
int main() {
    cin >> n;
    for(int i = 0 ; i < n; i++) {
        int a;
        cin >> a;
        mmin = min(mmin, a);
    }
    cout << mmin << endl;
    return 0;
}
