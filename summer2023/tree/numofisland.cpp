#include<vector>
#include<queue>
using namespace std;
#include<iostream>

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int count = 0;
        vector<int> DIR = {0, 1, 0, -1, 0};
        for(auto i = 0; i < grid.size(); ++i){
            for(auto j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '1'){ 
                    grid[i][j] = 'm';
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        int x = q.size();
                        for(auto k = 0; k < x; ++k){
                            pair<int,int> temp = q.front();
                            q.pop();
                            for(auto y = 0; y < 4; ++y){
                                int nr = temp.first + DIR[y], nc = temp.second + DIR[y+1];
                                if (nr < 0 || nr == grid.size() || nc < 0 || nc == grid[0].size() || grid[nr][nc] == 'm' || grid[nr][nc] == '0') continue;
                                grid[nr][nc] = 'm';
                                q.push({nr,nc});
                            }
                        }
                        
                    }
                    // for(auto row:grid){
                    //     for (auto chr:row){
                    //         cout << chr << ", ";   
                    //     }
                    //     cout << endl;
                    // }
                    // cout << "end of 1 matrix" << endl;
                    count++;
                }
            }
        }
        return count;
    }
};