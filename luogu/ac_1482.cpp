//
// Created by yangtao on 20-6-15.
//
#include <vector>
using namespace std;
class Solution {
public:
    int l , r;
    vector<int > a;
    bool check( int mid, int m, int k ) {
        int n = 0, cnt = 0;
        for(int i = 0; i < a.size(); i++) {
            if( a[i] > mid) {
                cnt += n / m;
                n = 0;
            } else {
                n++;
            }
        }
        return cnt >= k;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        a = bloomDay;
        l = -1, r = 1e9 + 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(check(mid, m, k)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return l;
    }
};

int main() {
    return 0;
}