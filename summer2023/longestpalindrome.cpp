#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map <char,int> hm;
        int result = 0;
        for (char chr : s){
            hm[chr]++;
        }
        for (auto it = hm.begin(); it != hm.end(); ++it){
            result += it->second / 2 * 2;
            if (result % 2 == 0 && it->second % 2 == 1){
                result += 1;
            }
        }
        return result;
    }
};