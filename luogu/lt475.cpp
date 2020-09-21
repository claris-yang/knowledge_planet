//
// Created by yangtao on 20-8-20.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    int ans = 0;
    for(auto v : houses) {
        int l = 0, r = heaters.size();
        while(l < r) {
            int mid = (l + r) >> 1;
            if( heaters[mid] < v ) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int ans1 = (r == 0) ? INT_MAX : abs(heaters[r - 1] - v);
        int ans2 = (r == heaters.size()) ? INT_MAX : abs(heaters[r] - v);
        ans = max(ans, min(ans1, ans2));
    }
    return ans;
}
int main() {

}
