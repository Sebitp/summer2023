#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


bool isValid(string s) {
    unordered_map<char,char> c_to_o = {{'}','{'},
                                        {']','['},
                                        {')','('}};
    vector<char> stack;
    for (char c : s) {
        if (c_to_o.count(c) == 0){
            stack.push_back(c);
        } else {
            if (!stack.empty() && stack.back() == c_to_o[c]){
                stack.pop_back();
            } else return false;
        }
    } 
    return stack.empty();
}