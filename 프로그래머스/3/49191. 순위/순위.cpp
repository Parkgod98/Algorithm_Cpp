#include <string>
#include <vector>

using namespace std;

void DFS(int cur, vector<vector<int>> &graph, vector<int> &visited){
    
    for (int &nxt : graph[cur]){
        if(!visited[nxt]){
            visited[nxt] = 1;
            
            DFS(nxt,graph,visited);
        }
    }
    
}

int solution(int n, vector<vector<int>> results) {
    
    int ans = 0;
    
    vector<int> win(n+1,0);
    vector<int> lose(n+1,0);
    vector<vector<int>> graph(n+1);
    
    for (vector<int> &v : results){
        graph[v[0]].push_back(v[1]);
    }
    
    
    for (int i = 1; i <= n; ++i){
        vector<int> visited(n+1,0);
        DFS(i,graph,visited);    
        
        for (int j = 1; j <= n; ++j){
            if(i == j || !visited[j])
                continue;
            
            win[i]++;
            lose[j]++;
        }
    }
    
    for (int i = 1; i <= n; ++i){
        if(win[i] + lose[i] == n -1)
            ++ans;
    }
    return ans;
}