#include <string>
#include <vector>

using namespace std;

void DFS(vector<int> &ans, int sr, int sc, int er, int ec, int len, vector<vector<int>> &arr){
    
    int standard = arr[sr][sc]; 
    for (int i = sr; i < er; ++i){
        for (int j = sc; j < ec; ++j){
            if(arr[i][j] != standard){
                DFS(ans,sr,sc,sr+len/2,sc+len/2,len/2,arr);
                DFS(ans,sr,sc+len/2,sr+len/2,ec,len/2,arr);
                DFS(ans,sr+len/2,sc,er,sc+len/2,len/2,arr);
                DFS(ans,sr+len/2,sc+len/2,er,ec,len/2,arr);
                return;
            }
        }

    }

    ans[standard]++;
    
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> ans(2,0);
    
    int sz = arr.size();
    
    DFS(ans,0,0,sz,sz,sz,arr);
    return ans;
}