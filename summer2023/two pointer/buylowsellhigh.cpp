#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int max = 0;
    auto l = prices.begin(), r = prices.begin()+1;
    while (r != prices.end()){
        if (*l > *r){
            l = r;
            r += 1;
        } else{
            int diff = *r - *l;
            r +=1;
            if  (diff > max){
                max = diff;
            }
        }
    }
    return max;
}