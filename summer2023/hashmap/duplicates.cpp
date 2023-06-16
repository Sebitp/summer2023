using namespace std;
#include <vector>
#include <unordered_map>


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_set<int> s;
        // for(auto num : nums){
        //     s.insert(num);
        // }
        // return s.size() != nums.size();
        unordered_map<int,int> h;
        for(auto num : nums){
            h[num]++;
            if(h[num] > 1) return true;
        }
        return false;
    }
};