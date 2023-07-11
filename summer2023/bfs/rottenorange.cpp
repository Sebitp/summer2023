#include <math.h>
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> DIR = {0,1,0,-1,0};
        int r = grid.size(), c = grid[0].size(), count = 0, fresh = 0;
        bool b = false;
        queue<pair<int,int>> q;
        // pair<int,int> target = {-1,-1};
        for(auto i = 0; i < r; ++i){
            for(auto j = 0; j < c; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                } else if (grid[i][j] == 1) fresh++;
            }
        }
        
        

        while(!q.empty()){
            int x = q.size();
            // for(auto i = 0; i < x; ++i){
            while (x--){
                pair<int,int> temp = q.front();
                q.pop();
                for(auto j = 0; j < 4; ++j){
                    int nr = temp.first + DIR[j], nc = temp.second + DIR[j+1];
                    if(nr < 0 || nr == r || nc < 0 || nc == c || grid[nr][nc] == 0 || grid[nr][nc] == 2 ) continue;
                    grid[nr][nc] = 2;
                    q.push({nr,nc});
                    fresh--;
                }
                
            }
            if(!q.empty()) count++;
            
        }

        // for(auto i = 0; i < r; ++i){
        //     for(auto j = 0; j < c; j++){
        //         if(grid[i][j] == 1){
        //             b = true;
        //         }
        //     }
        // }
        return fresh == 0 ? count : -1;
    }
};