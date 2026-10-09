#include <string>
#include <vector>

using namespace std;

void DFS(int cur, int visited[202], int &n, vector<vector<int>> &computers){
    if(visited[cur])
        return;
    
    visited[cur] = 1;
    
    for (int i = 0; i < n; ++i){
        if(i != cur && visited[i] == 0 && computers[cur][i] == 1){
            DFS(i,visited,n,computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int visited[202] = {0};
    int ans = 0;
    for (int i = 0; i < n; ++i){
        if(visited[i] == 0){
            visited[i] = 1;
            ++ans;
        }
        
        for (int j = 0; j < n; ++j){
            if(i != j && visited[j] == 0 && computers[i][j] == 1){
                DFS(j,visited,n,computers);
            }
        }
    }
    
    return ans;
}