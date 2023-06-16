#include <string>
using namespace std;
    
    
bool isPalindrome(string s) {

    size_t l = 0, r = s.size() - 1;
    while (r > l){
        if (isalnum(s[l]) && isalnum(s[r]) && tolower(s[l]) == tolower(s[r])){
            ++l;
            --r;
        } else if (!isalnum(s[l])){
            ++l;
        } else if (!isalnum(s[r])){
            --r;
        } else {
            return false;
        }
    }
    return true;
}