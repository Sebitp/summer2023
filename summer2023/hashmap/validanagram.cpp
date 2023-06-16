#include <string>
#include <map>
#include <algorithm>
using namespace std;



bool isAnagram(string s, string t) {
        map<char,int> hash_s;

        if (s.size() != t.size()){
            return false;
        }
        for (auto chr : s){
            hash_s[chr]++;
        }
        for (auto chr : t){
            hash_s[chr]--;
            if (hash_s[chr] < 0){
                return false;
            }
        }
        return true;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s == t;
        // for (char chr : s){
        //     auto it = find(t.begin(),t.end(),chr);
        //     if (it != t.end()){
        //         t.erase(it);
        //     }
            
        // }
        // return t.empty();
    }