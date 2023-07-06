#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> res;
        vector<int> comb;

        combinator(candidates,target,comb,0,0,res);
        return res;

    }

    void combinator(vector<int>& candidates, int target,vector<int> currComb, int currSum, int currIndex, vector<vector<int>>& res ){
        if(currSum>target) return;
        if(currSum == target){
            res.push_back(currComb);
            return;
        }
        
        for(int i=currIndex; i<candidates.size(); i++){ //try all possible options for the next level
            currComb.push_back(candidates[i]); //put 1 option into the combination
            currSum+=candidates[i];
            combinator(candidates, target, currComb, currSum, i, res); //try with this combination, whether it gives a solution or not.
            currComb.pop_back(); //when this option backtrack to here, remove this and go on to the next option.
            currSum-=candidates[i];
        }
    }


};