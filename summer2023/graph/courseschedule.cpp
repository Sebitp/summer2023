 #include <math.h>
using namespace std;
#include <vector>
#include <queue>
#include <unordered_map>

//Topology sort;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<vector<int>> adj(numCourses,vector<int>());
        vector<int> degree(numCourses,0);
        for(auto course : prerequisites){
            adj[course[1]].push_back(course[0]);
            degree[course[0]]++;
        }
        for(auto i = 0; i < numCourses; ++i){
            if(degree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int current = q.front(); q.pop(); numCourses--;
            for(auto neigh: adj[current]){
                if(--degree[neigh] == 0) q.push(neigh);
            }
        }
        return numCourses == 0;
    }
};