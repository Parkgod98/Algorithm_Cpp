#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Job{
    int id;
    int request_time;
    int cost;
};

struct cmp{
    bool operator()(const Job &a, const Job &b) const{
        if(a.cost != b.cost)
            return a.cost > b.cost;
        if(a.request_time != b.request_time)
            return a.request_time > b.request_time;
        return a.id > b.id;
    }
};

struct cmp2{
    bool operator()(const Job &a, const Job &b) const{
        if(a.request_time != b.request_time)
            return a.request_time > b.request_time;
        if(a.cost != b.cost)
            return a.cost > b.cost;
        return a.id > b.id;
    }
};


int solution(vector<vector<int>> jobs) {
    int start[502] = {0};
    int finish[502] = {0};
    
    priority_queue<Job,vector<Job>,cmp> pq;
    priority_queue<Job,vector<Job>,cmp2> pq2;
    
    for (int i = 0; i < jobs.size(); ++i){
        int rt = jobs[i][0];
        int c = jobs[i][1];
        
        pq2.push({i,rt,c});
        start[i] = rt;
    }
    
    Job fst = pq2.top();
    pq2.pop();
    int cur_time = fst.request_time;
    pq.push(fst);
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        // cout << it.id << " " << cur_time << "\n";
        
        if(cur_time < it.request_time)
            cur_time = it.request_time;
        cur_time += it.cost;
        finish[it.id] = cur_time;
        
        while(!pq2.empty() && pq2.top().request_time <= cur_time){
            auto p2 = pq2.top();
            pq.push(p2);
            pq2.pop();
        }
        if(pq.empty() && !pq2.empty()){
            cur_time = pq2.top().request_time;
            pq.push(pq2.top());
            pq2.pop();
        }
    }
    
    int sum = 0;
    for (int i = 0; i < jobs.size(); ++i){
        sum += finish[i] - start[i];
    }
    sum /= (int)jobs.size();
    
    return sum;
}