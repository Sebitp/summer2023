using namespace std;
#include <vector>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0], counter = 1;
        for(auto i = 1; i < nums.size(); ++i){
            if(nums[i] == major){
                counter++;
            } else if (counter == 0){
                major = nums[i];
                counter = 1;
            } else counter--;
        }
        return major;
    }
};