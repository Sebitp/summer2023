#include<vector>
#include<queue>
using namespace std;
#include<iostream>

// int updateFound(vector<vector<int>>& mat, int count, int i, int j){
//         queue<pair<int,int>> q;
//         q.push(make_pair(i,j));
//         while(!q.empty()){
//             for(auto i = 0; i < q.size(); ++i){
//                 pair<int,int> temp = q.front();
//                 q.pop();
//                 if(mat[temp.first][temp.second] != 0 ){
//                     if(temp.first - 1 >= 0){
//                         q.push(make_pair(temp.first - 1,temp.second));
//                     }
//                     if(temp.first + 1 < mat.size()){
//                         q.push(make_pair(temp.first + 1,temp.second));
//                     }
//                     if(temp.second - 1 >= 0){
//                         q.push(make_pair(temp.first,temp.second - 1));
//                     }
//                     if(temp.second + 1 < mat[0].size()){
//                         q.push(make_pair(temp.first,temp.second + 1));
//                     } 
                    
//                 } else return count;
//                 count++;
//             }
            
//         }
//         return count; 
//     }
int updateFound(vector<vector<int>>& mat, int count, int i, int j){
    queue<pair<int,int>> q;
    pair<int,int> o_pair = {i,j};
    q.push(make_pair(i,j));
    while(!q.empty()){
        for(auto x = 0; x < q.size(); ++x){
            pair<int,int> temp = q.front();
            q.pop();
            
            if(mat[temp.first][temp.second] != 0 ){
                if(temp.first - 1 >= 0 && (make_pair(temp.first - 1,temp.second) != o_pair)){
                    if(mat[temp.first - 1][temp.second] == 0){
                        return ++count;
                    }
                    q.push(make_pair(temp.first - 1,temp.second));
                }
                if(temp.first + 1 < mat.size() && (make_pair(temp.first + 1,temp.second) != o_pair)){
                    if(mat[temp.first + 1][temp.second] == 0){
                        return ++count;
                    }
                    q.push(make_pair(temp.first + 1,temp.second));
                }
                if(temp.second - 1 >= 0 && (make_pair(temp.first ,temp.second-1) != o_pair)){
                    if(mat[temp.first][temp.second-1] == 0){
                        return ++count;
                    }
                    q.push(make_pair(temp.first,temp.second - 1));
                }
                if(temp.second + 1 < mat[0].size() && (make_pair(temp.first ,temp.second+1) != o_pair)){
                    if(mat[temp.first][temp.second+1] == 0){
                        return ++count;
                    }
                    q.push(make_pair(temp.first,temp.second + 1));
                } 
                count++;
            }  
                
            
        }

        
    }
    return count; 
}
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans = mat;
        int count = 0;
        for(auto i = 0; i < mat.size(); i++){
            for(auto j = 0; j < mat[0].size(); j++){
                ans[i][j] = updateFound(mat,count,i,j);
            }
        }
        return ans;

        }
int main(){
    vector<vector<int>> mat;
    mat.push_back({0,0,0});
    mat.push_back({0,1,0});
    mat.push_back({1,1,1});
    mat = updateMatrix(mat);
    for(auto i:mat){
        for (auto x:i){
            cout << x << ',';
        }
        cout << endl;
    }

}

// class Solution {
// public:
//     vector<int> DIR = {0, 1, 0, -1, 0};
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int m = mat.size(), n = mat[0].size();
//         queue<pair<int, int>> q;
//         for (int r = 0; r < m; ++r)
//             for (int c = 0; c < n; ++c)
//                 if (mat[r][c] == 0) q.emplace(r, c);
//                 else mat[r][c] = -1; // Marked as not processed yet!

//         while (!q.empty()) {
//             auto [r, c] = q.front(); q.pop();
//             for (int i = 0; i < 4; ++i) {
//                 int nr = r + DIR[i], nc = c + DIR[i+1];
//                 if (nr < 0 || nr == m || nc < 0 || nc == n || mat[nr][nc] != -1) continue;
//                 mat[nr][nc] = mat[r][c] + 1;
//                 q.emplace(nr, nc);
//             }
//         }
//         return mat;
//     }
// };