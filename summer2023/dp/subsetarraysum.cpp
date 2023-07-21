#include <math.h>
using namespace std;
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <unordered_set>
#include <numeric>


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int res = accumulate(nums.begin(),nums.end(),0);
        if(res%2 != 0) return false;
        unordered_set<int> dp;
        dp.insert(0);
        res/=2;
        for(int i = 0; i < nums.size();++i){
            unordered_set<int> ndp(dp);
            for(auto s:dp){
                if(nums[i] + s == res) return true;
                ndp.insert(s+nums[i]);
 
                
            }
            dp = ndp;
        }
        return false;
        int resultant_sums = 0 ;
        
        //Adding all the elements of our vector
        // for (auto x : nums)
        //     resultant_sums +=x;
        
        // //Now think that the sum is odd in this special case we can never find two equal partitions
        // if(resultant_sums % 2) return false;
        // //Finding the half off the resultant sum
        // resultant_sums /= 2;
        
        // //dp vector for storing the results of previous row i.e dp will keep for each number if it has a satisfying subset or not
        // vector<bool> dp(resultant_sums+1,false);
        // dp[0]=true;
        // for(auto x:nums){
        //     for(int i=resultant_sums;i>=x;i--){
        //         dp[i] = dp[i] || dp[i-x] ;//The "or" operator is used because for each number, either we use it or we don't
        //     }
        // }
        // return dp[resultant_sums];
    }
};
