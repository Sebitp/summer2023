#include<string>
#include<iostream>
using namespace std;
#include<unordered_set>
#include<algorithm>
int lengthOfLongestSubstring(string s) {
    unordered_set<char> char_set;
    int l = 0, r = 0, result = 0;
    while(r < s.size()){
        while(char_set.find(s[r]) != char_set.end()){
            char_set.erase(s[l]);
            l++;
        }
        char_set.insert(s[r]);
        
        result = max(result, r- l + 1);
        r++;
    }
    return result;
}
int main(){
    string s = "pwwkew";
    cout<<lengthOfLongestSubstring(s);
}