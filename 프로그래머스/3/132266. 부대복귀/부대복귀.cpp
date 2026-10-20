#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    queue<int> q;
    vector<int> dist(n,0);
    dist[destination-1] = 1;
    
    vector<vector<int>> v(n);
    
    for (vector<int> &r : roads){
        int s = r[0]-1;
        int e = r[1]-1;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    
    q.push(destination-1);
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        for (int &nxt : v[it]){
            if(dist[nxt] == 0){
                q.push(nxt);
                dist[nxt] = dist[it] + 1;
            }
        }
    }
    
    vector<int> ans;
    for (int &s : sources){
        if(dist[s-1] != 0){
            ans.push_back(dist[s-1]-1);
        }
        else
            ans.push_back(-1);
    }
    
    return ans;
}