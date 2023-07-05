#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;
            //left
            if(nums[mid] >= nums[l]){
                if(target > nums[mid] || target < nums[l]){
                    l = mid + 1;
                } else r = mid - 1;
            //right
            } else {
                if(target < nums[mid] || target > nums[r]){
                    r = mid - 1;
                } else l = mid +1; 
            }
        } 
        return -1;
    }
};