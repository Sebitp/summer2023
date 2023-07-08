#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);

        for(auto i = 1; i < intervals.size(); ++i){
            if(res.back()[1] >= intervals[i][0]){
                res.back()[1] = max(intervals[i][1],res.back()[1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
        // if(intervals.size() == 1) return intervals;
        // int l = 0; r = 1;
        // while(r < intervals.size()){
        //     if(intervals[l][1] >= intervals[r][0]){
        //         temp[0] = intervals[l][0];
        //         temp[1] = max(intervals[l][1],intervals[r][1]);
        //         r++;
        //     } 
        // }
    }
};