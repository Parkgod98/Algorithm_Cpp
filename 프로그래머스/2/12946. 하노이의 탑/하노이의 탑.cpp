#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int from, int inter, int to, vector<vector<int>> &ans){
    if(n == 1){
        ans.push_back({from,to});
    }
    else{
        hanoi(n-1,from,to,inter,ans);
        ans.push_back({from,to});
        hanoi(n-1,inter,from,to,ans);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> ans;
    
    hanoi(n,1,2,3,ans);
    return ans;
}