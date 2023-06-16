#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(auto i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            int l = i+1, r = nums.size()-1;
            while(l<r){
                int sums = nums[i] + nums[l] + nums[r];
                if(sums > 0) r--;
                else if (sums < 0) l++;
                else{
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(nums[l] == nums[l-1] && l < r ) l++;
                }
            }
        }
        return res;
    }
};