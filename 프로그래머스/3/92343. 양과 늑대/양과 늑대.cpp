#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> infoV;
vector<vector<int>> graph;
set<vector<int>> seen;
int ans;

void DFS(vector<int> visited, int sheep, int wolf){
    
    if(seen.find(visited) != seen.end())
        return;
    
    seen.insert(visited);
    
    ans = max(ans,sheep);
    
    for (int cur = 0; cur < infoV.size(); ++cur){
        if(!visited[cur])
            continue;
        
        for (int &nxt : graph[cur]){
            if(visited[nxt])
                continue;
            
            int ns = sheep;
            int nw = wolf;
            
            if(infoV[nxt] == 0)
                ++ns;
            else
                ++nw;
            
            if(ns <= nw)
                continue;
            
            visited[nxt] = 1;
            DFS(visited,ns,nw);
            visited[nxt] = 0;
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    ans = 0;
    int n = info.size();
    infoV = info;
    graph = vector<vector<int>>(n);
    
    for (vector<int> &e : edges){
        graph[e[0]].push_back(e[1]);
    }
    
    vector<int> visited(n,0);
    visited[0] = 1;
    DFS(visited,1,0);
    return ans;
}