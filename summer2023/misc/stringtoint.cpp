using namespace std;
#include <string>
#include <limits.h>

class Solution {
public:
    int myAtoi(string s) {
        // istringstream iss(s);
        // int x = 0;
        // iss >> x;
        // return x;

        int i = 0, n = s.size(), res = 0;
        while(i<n && s[i] == ' ') ++i;
        bool neg = false;
        if(i<n && s[i] == '-') {
           neg = true; 
           i++;
        } else if (i<n && s[i] == '+') ++i;

        while(i<n && isdigit(s[i])){
            int dig = s[i]-'0';
            if(res > (INT_MAX / 10) || (res == (INT_MAX / 10) && dig > 7)){
                return neg ? INT_MIN : INT_MAX;
            }  
            res = (res*10) + dig ;
            ++i;

        }
        return neg ? -res : res;
    }
};