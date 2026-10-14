#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>

struct Node{
    int idx;
    int num;
};

struct cmp{
    bool operator()(const Node &a, const Node &b) const {
        if(a.num != b.num)
            return a.num < b.num;
        return a.idx > b.idx;
    };
};


using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string,int> genre_to_idx;
    
    int idx = 0;
    priority_queue<Node,vector<Node>,cmp> pq[101];
    
    int g_count[101] = {0};
    for (string &s : genres){
        if(genre_to_idx.find(s) == genre_to_idx.end()){
            genre_to_idx[s] = idx++;
        }
    }
    
    for (int i = 0; i < plays.size(); ++i){
        pq[genre_to_idx[genres[i]]].push({i,plays[i]});
        g_count[genre_to_idx[genres[i]]] += plays[i];
    }
    
    vector<int> idx_list(idx);
    for (int i = 0; i < idx; ++i){
        idx_list[i] = i;
    }
    
    sort(idx_list.begin(),idx_list.end(),[&](int a, int b){
        return g_count[a] > g_count[b];
    });
    
    vector<int> ans;
    
    for (int &i : idx_list){
        int cnt = 0;
        while(!pq[i].empty() && cnt < 2){
            ans.push_back(pq[i].top().idx);
            pq[i].pop();
            ++cnt;
        }
    }
    return ans;
}