#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // unordered_map<char,int> hashmap;
        // for (char c : magazine){
        //     hashmap[c]++;
        // }
        // for (char c : ransomNote){
        //     // if (!hashmap[c]){
        //     //     return false;
        //     // } else hashmap[c]--;
        //     auto it = hashmap.find(c);
        //     if (it != hashmap.end() && hashmap[c] > 0){
        //         hashmap[c] -= 1;
        //     } else return false;

        // }
        // return true;

        unordered_map < char, int> mp;
        
        for(auto c: magazine)
            mp[c]++;
        
        for(auto c: ransomNote)
        {
            if(!mp[c])
                return false;
            
            mp[c]--;
        }
        
        return true;
    }
};