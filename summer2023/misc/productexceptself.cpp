#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);
        int prefix = 1;
        for(auto i = 0; i < n; i++){
            res[i] = prefix;
            prefix *= nums[i];
        }
        int post = 1;
        for(auto i = n-1; i >= 0; --i){
            res[i] *= post;
            post *= nums[i];
        }
        return res;
    }
};