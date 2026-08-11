#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> v = vector<vector<int>>(n,vector<int>(n,0));
    
    for (int i = 0; i < n; ++i){
        v[i][i] = 1;
    }
    return v;
}