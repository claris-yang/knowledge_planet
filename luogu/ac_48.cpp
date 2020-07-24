//
// Created by yangtao on 20-5-28.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num, res;

class Solution {
public:
    int moreThanHalfNum_Solution(vector<int>& nums) {
        if(nums.size() <= 0) return 0;
        num = nums[0], res = 1;
        for(int i = 1; i < nums.size(); i++) {
            if( num != nums[i] && res > 0) {
                res--;
            } else {
                res++;
                num = nums[i];
            }
        }
        return num;
    }
};

int main() {
    Solution s;
    vector<int> a = {1,2,1,1,3};
    int res = s.moreThanHalfNum_Solution(a);
    cout << res << endl;
    return 0;
}