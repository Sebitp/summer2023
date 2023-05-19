#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if (image[sr][sc] == color) return image;
    fill(image,sr,sc,image[sr][sc],color);
    return image;
}
void fill(vector<vector<int>>& image, int sr, int sc, int color, int new_color){
    if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != color) return;
    image[sr][sc] = new_color;
    fill(image,sr+1,sc,color,new_color);
    fill(image,sr-1,sc,color,new_color);
    fill(image,sr,sc+1,color,new_color);
    fill(image,sr,sc-1,color,new_color);

}