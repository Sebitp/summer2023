#include<vector>
#include<map>
using namespace std;
#include<math.h>
#include<iostream>
#include<algorithm>

    double getDistance(vector<int> point){
        return sqrt(pow(point[0],2) + pow(point[1],2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<vector<int>,double>> h;
        vector<vector<int>> res;
        for (auto v: points){
            h.push_back(make_pair(v,getDistance(v)));
        }
        sort(h.begin(),h.end(),[](pair<vector<int>,double>& a,
         pair<vector<int>,double>& b){
             return a.second < b.second;
         });
        for(auto it = h.begin(); it != h.end(); ++it){
            res.push_back(it->first);
            --k;
            if(k == 0) break;
        }
        return res;
        
    }

        // sort(points.begin(),points.end(),[](vector<int> a, vector<int> b){
        // return sqrt(pow(a[0],2) + pow(a[1],2)) < sqrt(pow(b[0],2) + pow(b[1],2));;
        // });
        // vector<vector<int>> newv(points.begin(),points.begin()+k);
        // return newv; 


int main(){
    vector<vector<int>> res;
    res.push_back({3,3});
    res.push_back({5,-1});
    res.push_back({-2,4});
    res = kClosest(res,2);
    for(auto i:res){
        for (auto x:i){
            cout << x << ',';
        }
        cout << endl;
    }

}