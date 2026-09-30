#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Point{
    int y,x;
};

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> ans;
    
    vector<vector<int>> v = vector<vector<int>>(rows,vector<int>(columns));
    
    int num = 1;
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < columns; ++j)
            v[i][j] = num++;
    }
    
    for (vector<int> &q : queries){
        int sr = q[0] - 1;
        int sc = q[1] - 1;
        
        int er = q[2] - 1;
        int ec = q[3] - 1;
        
        vector<Point> p_list;
        vector<int> value_list;
        for (int j = sc; j <= ec; ++j){
            p_list.push_back({sr,j});
            value_list.push_back(v[sr][j]);
        }
        for (int i = sr+1; i <= er; ++i){
            p_list.push_back({i,ec});
            value_list.push_back(v[i][ec]);
        }
        for (int j = ec - 1; j >= sc; --j){
            p_list.push_back({er,j});
            value_list.push_back(v[er][j]);
        }
        for (int i = er - 1; i >= sr + 1; --i){
            p_list.push_back({i,sc});
            value_list.push_back(v[i][sc]);
        }
        
        int sz = p_list.size();
        int mn = 999999999;
        for (int i = 1; i <= sz; ++i){
            int y = p_list[i%sz].y;
            int x = p_list[i%sz].x;
            v[y][x] = value_list[i-1];
            mn = min(value_list[i-1],mn);
        }
        
        ans.push_back(mn);
        
    }
    return ans;
}