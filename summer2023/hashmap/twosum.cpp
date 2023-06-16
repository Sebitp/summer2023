#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,size_t> mapped;
        vector<int> answer;

        for (size_t i = 0; i<nums.size(); ++i){
            auto it = mapped.find(target-nums[i]);
            if ( it != mapped.end()){
                answer.push_back(i);
                answer.push_back(it->second);
                return answer;
            } else {
                mapped[nums[i]] = i;

            }
        }
        return answer; 
    }


int main(){
    vector<int> x {3,2,4};
    vector answer = twoSum(x,6);
    for (auto x :answer){
        cout << x;
    }
}