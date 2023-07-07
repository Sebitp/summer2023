
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        permutation(nums, 0, res);
        return res;
    }

    void permutation(vector<int>& nums, int index,  vector<vector<int>>& res){
        if(index == nums.size()-1){
            res.push_back(nums);
            return;
        }
        for(auto i = index; i <= nums.size()-1; ++i){

            swap(nums[index],nums[i]);
            permutation(nums, index+1, res);
            swap(nums[index],nums[i]);
        }
    }
};