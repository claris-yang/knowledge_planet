//
// Created by yangtao on 19-11-11.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> dp;
int binary_find(int n, vector<int> &nums) {
    int l = 0, r = dp.size() - 1;
    while( l < r ) {
        int m = (l+r) / 2;
        if( dp[m] >= n) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}
int lengthOfLIS(vector<int>& nums) {

    if(nums.size() <=0) return 0;
    dp.push_back(nums[0]);
    int ans = 0;
    for(int i = 1; i < nums.size(); i++) {
        if( nums[i] > dp[ans] ) {
            dp.push_back(nums[i]) , ans++;
        } else {
            int p = binary_find( nums[i], nums);
            dp[p] = nums[i];
        }
    }
    return ans + 1;
}

int main() {
    vector<int> nums = {10,9,2,5,3,4};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}