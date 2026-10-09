#include <string>
#include <vector>

using namespace std;

void DFS(int cur, int visited[202], int &visited_token, int &n, vector<vector<int>> &computers){
    if(visited[cur])
        return;
    
    visited[cur] = visited_token;
    
    for (int i = 0; i < n; ++i){
        if(i != cur && visited[i] == 0 && computers[cur][i] == 1){
            DFS(i,visited,visited_token,n,computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int visited[202] = {0};
    
    int visited_token = 1;
    int ans = 0;
    for (int i = 0; i < n; ++i){
        if(visited[i] == 0){
            visited[i] = visited_token;
            ++ans;
        }
        
        bool f = false;
        for (int j = 0; j < n; ++j){
            if(i != j && visited[j] == 0 && computers[i][j] == 1){
                DFS(j,visited,visited[i],n,computers);
                f = true;
            }
        }
        if(f)
            ++visited_token;
    }
    
    return ans;
}