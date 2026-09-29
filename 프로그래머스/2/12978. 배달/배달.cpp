#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 999999999

struct Edge{
    int nxt;
    int cost;
    
    bool operator<(const Edge &other) const{
        if(cost != other.cost)
            return cost > other.cost;
        return nxt > other.nxt;
    }
};

vector<vector<Edge>> edge_list;

vector<int> distra(int n, int K){
    vector<int> dist(edge_list.size(),INF);
    priority_queue<Edge> pq;
    
    dist[n] = 0;
    pq.push({n,0});
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        int cur_node = it.nxt;
        int cur_cost = it.cost;
        
        if(dist[cur_node] < cur_cost)
            continue;
        
        for (auto &iit : edge_list[cur_node]){
            int nxt = iit.nxt;
            int edge_cost = iit.cost;
            
            int nxt_cost = cur_cost + edge_cost;
            
            if(nxt_cost >= dist[nxt] || nxt_cost > K)
                continue;
            
            dist[nxt] = nxt_cost;
            pq.push({nxt,nxt_cost});
        }
    }
    
    return dist;
}

int solution(int N, vector<vector<int>> road, int K) {
    
    
    edge_list = vector<vector<Edge>>(N+1);
    for (vector<int> &v : road){
        int a = v[0];
        int b = v[1];
        int cost = v[2];
        
        edge_list[a].push_back({b,cost});
        edge_list[b].push_back({a,cost});
    }
    
    int sum = 0;
    vector<int> ans = distra(1, K);
    
    for (int i = 1; i <= N; ++i){
        if(ans[i] != 0 && ans[i] <= K)
            ++sum;
    }

    return sum+1;
}