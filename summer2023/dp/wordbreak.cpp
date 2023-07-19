#include <math.h>
using namespace std;
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp.back()= true;
        for(int i = s.size()-1; i>=0; i--){
            for(auto w:wordDict){
                if(i+w.size() <= s.size() && s.substr(i,w.size()) == w){
                    dp[i] = dp[i+w.size()];
                }
                if(dp[i]) break;
            }
        }
        return dp[0];
    }
    
};