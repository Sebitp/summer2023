using namespace std;
#include <string>
#include <algorithm>
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int digit_a = 0, digit_b = 0, carry = 0, total = 0;
        for(auto i = 0; i<max(a.size(),b.size()); ++i){
            digit_b = i < b.size() ? b.at(i) - '0' : 0; 
            digit_a = i < a.size() ? a.at(i) - '0' : 0; 

            total = digit_a + digit_b + carry;
            char chr = '0' + (total%2);
            result = chr + result;
            carry = total / 2;

        }
        if (carry){
            result = '1' + result;
        }
        return result;
    }

};