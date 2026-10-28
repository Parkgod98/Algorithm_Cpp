#include <string>
#include <vector>
using namespace std;
int ans;

vector<int> infoV;
vector<vector<int>> graph;
int seen[200000];

void DFS(int mask, int sheep, int wolf){
    
    if(seen[mask] == 1)
        return;
    
    seen[mask] = 1;
    ans = max(ans,sheep);
    
    
    for (int cur = 0; cur < infoV.size(); ++cur){
        if((mask & (1 << cur)) == 0)
            continue;
        
        for (int &nxt : graph[cur]){
            if(mask & (1 << nxt))
                continue;
            
            int ns = sheep;
            int nw = wolf;
            
            if(infoV[nxt] == 0)
                ++ns;
            else
                ++nw;
            
            if(ns <= nw)
                continue;
            
            DFS(mask | (1 << nxt),ns,nw);
        }
    }
    
}


int solution(vector<int> info, vector<vector<int>> edges) {

    int n = info.size();
    infoV = info;
    graph = vector<vector<int>>(n);
    
    for (vector<int> &e : edges){
        graph[e[0]].push_back(e[1]);
    }
    
    DFS(1,1,0);
    
    return ans;
}