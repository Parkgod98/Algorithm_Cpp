#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int visited[102][102] = {0};
    int mx = 500;
    vector<vector<int>> v(n+1);
    for (vector<int> &edge : wires){
        v[edge[0]].push_back(edge[1]);
        v[edge[1]].push_back(edge[0]);
        visited[edge[0]][edge[1]] = visited[edge[1]][edge[0]] = 1;
    }
    
    queue<int> q;
    for (int i = 0; i < n - 1; ++i){
        int a = wires[i][0];
        int b = wires[i][1];
        visited[a][b] = visited[b][a] = 0;
        
                
        int cnt1 = 0;
        q.push(a);
        int node_visited[102] = {0};
        node_visited[a] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            ++cnt1;            
            for (int &nxt : v[cur]){
                if(!node_visited[nxt] && visited[cur][nxt]){
                    q.push(nxt);
                    node_visited[nxt] = 1;
                }
            }
        }
        int cnt2 = 0;
        int node_visited2[102] = {0};
        
        q.push(b);
        node_visited2[b] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            ++cnt2;            
            for (int &nxt : v[cur]){
                if(!node_visited2[nxt] && visited[cur][nxt]){
                    q.push(nxt);
                    node_visited2[nxt] = 1;
                }
            }
        }
        mx = min(mx,abs(cnt1-cnt2));
        
        visited[a][b] = visited[b][a] = 1;
    }
    return mx;
}