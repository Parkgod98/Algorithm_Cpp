#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<int> visited(n,0);
    vector<vector<int>> v(n);
    
    for (vector<int> &e : edge){
        v[e[0]-1].push_back(e[1]-1);
        v[e[1]-1].push_back(e[0]-1);
    }
    
    queue<int> q;
    
    q.push(0);
    visited[0] = 1;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for (int &nxt : v[cur]){
            if(!visited[nxt]){
                q.push(nxt);
                visited[nxt] = visited[cur]+1;
            }
        }
    }
    
    int mx = 0;
    for (int i = 0; i < n; ++i){
        mx = max(visited[i],mx);
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i){
        if(visited[i] == mx)
            ++ans;
    }
    return ans;
}