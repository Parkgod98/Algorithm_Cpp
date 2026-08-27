#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    
    int sz = arr1.size();
    int sz2 = arr1[0].size();
    
    for (int i = 0; i < sz; ++i){
        for (int j = 0; j < sz2; ++j)
            arr1[i][j] += arr2[i][j];
    }
    return arr1;
}