#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int length = intervals.size(), i = 0;
        vector<vector<int>> ans;
        

        while(i < length && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            ++i;
        }

        while(i < length && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            ++i;
        }

        ans.push_back(newInterval);

        while(i < length){
            ans.push_back(intervals[i]);
            ++i;
        }
        
        return ans;

        // for (auto i = 0; i < intervals.size(); i++){
        //     if (newInterval[1] < intervals[i][0]){
        //         ans.push_back(newInterval);
        //         ans.insert(ans.end(), intervals.begin()+i, intervals.end() );
        //         return ans;
        //     } else if (newInterval[0] > intervals[i][1]){
        //         ans.push_back(intervals[i]);
        //     } else{
        //         newInterval[0] = min(intervals[i][0],newInterval[0]);
        //         newInterval[1] = max(intervals[i][1],newInterval[1]);               
        //     }
        //     ans.push_back(newInterval);
        // } return ans;


        // if (!intervals.size()){
        //     ans.push_back(newInterval);
        //     return ans;
        // } else if (intervals[0][0] > newInterval[1]){
        //     ans.push_back(newInterval);
        // }
        // for (auto i = 0; i < intervals.size(); i++){
        //     if (intervals[i][1] < newInterval[0]){
        //         ans.push_back(intervals[i]);
        //         if(i == intervals.size()-1){
        //             ans.push_back(newInterval);
        //         }
        //     } else if (intervals[i][0] <= newInterval[1]){
        //         while(i < intervals.size() && intervals[i][0] <= newInterval[1]){
        //             newInterval[0] = min(intervals[i][0],newInterval[0]);
        //             newInterval[1] = max(intervals[i][1],newInterval[1]);
        //             ++i;
        //         }

        //         ans.push_back(newInterval);
        //         i--;
        //     } else {
        //         ans.push_back(intervals[i]);
        //     }
        // }
        // return ans;
    }

};