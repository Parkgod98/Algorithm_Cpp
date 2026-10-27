#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 99999999

using namespace std;
int sz;

struct Edge{
    int nxt;
    int cost;
    
    bool operator<(const Edge &other) const{
        if(cost != other.cost)
            return cost > other.cost;
        return nxt > other.nxt;
    }
};
vector<vector<Edge>> v;


vector<int> distra(int start){
    vector<int> dist(sz+1,INF);
    
    priority_queue<Edge> pq;
    dist[start] = 0;
    pq.push({start,0});
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        int cur = it.nxt;
        int cur_cost = it.cost;
        
        if(cur_cost > dist[cur])
            continue;
        
        for (auto &iit : v[cur]){
            int nxt = iit.nxt;
            int nxt_cost = iit.cost;
            
            if(cur_cost + nxt_cost >= dist[nxt])
                continue;
            
            pq.push({nxt,cur_cost+nxt_cost});
            dist[nxt] = cur_cost + nxt_cost;
        }
    }
    
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    sz = n;
    int ans = INF;
    v = vector<vector<Edge>>(n+1);
    
    for (vector<int> &f : fares){
        int s = f[0];
        int e = f[1];
        int c = f[2];
        
        v[s].push_back({e,c});
        v[e].push_back({s,c});
    }
    
    vector<int> s_dist = distra(s);
    
    for (int i = 1; i <= n; ++i){
        vector<int> i_dist = distra(i);
        
        int cur_cost = s_dist[i] + i_dist[a] + i_dist[b];
        ans = min(ans,cur_cost);
    }
    
    return ans;
}