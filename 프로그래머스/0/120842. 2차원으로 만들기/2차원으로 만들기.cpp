#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    int r = num_list.size()/n;
    int c = n;
    
    vector<vector<int>> v = vector<vector<int>>(r,vector<int>(c));
    int k = 0;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            v[i][j] = num_list[k++];
        }
    }
    return v;
}