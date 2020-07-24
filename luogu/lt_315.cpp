//
// Created by yangtao on 20-6-8.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--) {
            int j = i + 1;
            int val = nums[j-1];
            for(; j < nums.size(); j++) {
                if(nums[j] >= val) nums[j-1] = nums[j];
                else break;
            }
            nums[j-1] = val;
            res[i] = nums.size() - j ;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> a = {5, 2, 6, 1};
    s.countSmaller(a);
    return 0;
}