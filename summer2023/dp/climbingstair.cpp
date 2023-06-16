#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 1, total = 0;
        if (n == 1){
            return n;
        } 
        while(n > 1){
            total = one + two;
            two = one;
            one = total;
            n--;
        }
        return total;
    }
};