#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while (l <= r){
        int m = (l+r)/2;
        if (nums[m] > target){
            r = m-1;
        } else if (nums[m] < target){
            l = m+1;
        } else return m;
    }
    return -1;


        // int index = (nums.size() - 1)/2;
        // if (nums[index] == target){
        //     return index;
        // } else if (nums[index] > target){
        //     vector<int> new_v(nums.begin(),nums.begin()+index);
        //     search(new_v, target);
        //     return -1;
        // } else if (nums[index] < target){
        //     vector<int> new_v(nums.begin()+index, nums.end());
        //     search(new_v, target);
        //     return -1;
        // } else return -1;
    }