#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool is_blocked(int y, int x, int n) {
    if (y < 0 || x < 0 || y >= n || x >= n)
        return true;
    return false;
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> v(n, vector<int>(n, 0));

    int y, x;
    y = x = 0;
    int start = 1;
    int dy[4] = { 0,1,0,-1 };
    int dx[4] = { 1,0,-1,0 };
    int i = 0;
    while (start <= n*n) {
        v[y][x] = start++;
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!is_blocked(ny, nx, n) && v[ny][nx] == 0) {
            y = ny;
            x = nx;
        }
        else {
            if (i == 3)
                i = 0;
            else 
                i++;
            y = y + dy[i];
            x = x + dx[i];
        }
    }

    return v;
}