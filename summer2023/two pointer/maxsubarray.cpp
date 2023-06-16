#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sub = nums[0], cur_sum = 0;
        for(auto num : nums){
            if (cur_sum < 0) cur_sum = 0;
            cur_sum += num;
            max_sub = max(max_sub,cur_sum); 
        }
        return max_sub;
    }
};