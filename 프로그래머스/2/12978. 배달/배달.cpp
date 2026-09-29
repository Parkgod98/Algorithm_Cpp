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

vector<Edge> e_list[52];

vector<int> distra(int start, int K, int N){
    vector<int> dist(N+1,INF);
    
    priority_queue<Edge> pq;
    pq.push({start,0});
    dist[start] = 0;
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        int cur_node = it.nxt;
        int cur_cost = it.cost;
        
        if(dist[cur_node] < cur_cost)
            continue;
        
        for (auto &iit : e_list[cur_node]){
            int nxt = iit.nxt;
            int nxt_cost = iit.cost;
            
            if(dist[nxt] <= cur_cost + nxt_cost || cur_cost + nxt_cost > K)
                continue;
            
            pq.push({nxt,cur_cost + nxt_cost});
            dist[nxt] = cur_cost + nxt_cost;
        }
    }
    
    return dist;
}

int solution(int N, vector<vector<int> > road, int K) {
    
    for (vector<int> &e : road){
        int a = e[0];
        int b = e[1];
        int cost = e[2];
        
        e_list[a].push_back({b,cost});
        e_list[b].push_back({a,cost});
    }
    
    vector<int> dist = distra(1,K,N);
    
    int ans = 0;
    for (int i = 1; i <= N; ++i){
        if(dist[i] != 0 && dist[i] <= K)
            ++ans;
    }

    return ans+1;
}