//
// Created by yangtao on 19-10-12.
//

#include <iostream>
#include <algorithm>
using namespace std;
struct Hill {
    int x, y;
    bool operator<(const Hill & b) const {
        if(y > b.y) {
            return true;
        } else {
            return false;
        }
    }

};
bool cmp(int x1, int y1, int x2, int y2) {
    if( x1 < x2) {
        if(x2 - y2 <= x1 - y1) {
            return false; // 包含
        } else {
            return true;
        }
    } else if( x1 > x2 ){
        if(x2 + y2 >= x1 + y1 ) {
            return false;
        } else {
            return true;
        }
    } else if(x1 == x2) {
        return false;
    }
    return true;
}

Hill h[500005];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Hill t;
        cin >> t.x >> t.y;
        h[i] = t;
    }
    sort(h, h + n);

    int res = 1;
    for(int i = 1; i < n; i++) {

        bool flag = true;
        for(int j = 0; j < i; j++) {
            if( cmp(h[i].x, h[i].y, h[j].x, h[j].y) == false ) {
                flag = false;
                break;
            }
        }
        if(flag) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}