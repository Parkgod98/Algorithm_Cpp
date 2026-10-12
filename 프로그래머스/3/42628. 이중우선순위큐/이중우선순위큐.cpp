#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int num;
    int id;
};

struct MaxCmp{
    bool operator()(const Node &a, const Node &b) const{
        return a.num < b.num;
    }
};

struct MinCmp{
    bool operator()(const Node &a, const Node &b) const{
        return a.num > b.num;
    }
};

vector<int> solution(vector<string> operations){
    vector<int> ans(2);
    
    priority_queue<Node,vector<Node>,MaxCmp> pq;
    priority_queue<Node,vector<Node>,MinCmp> pq2;
    
    
    int id = 0;
    vector<int> alive(operations.size(),0);
    
    for (string &s : operations){
        char com = s[0];
        
        int k = stoi(s.substr(2));
        
        if(com == 'I'){
            pq.push({k,id});
            pq2.push({k,id});
            alive[id] = 1;
            ++id;
        }
        else{
            if(k == 1){
                if(!pq.empty()){
                    alive[pq.top().id] = 0;
                    pq.pop();
                }
            }
            else{
                if(!pq2.empty()){
                    alive[pq2.top().id] = 0;
                    pq2.pop();
                }
            }
        }
        while(!pq.empty() && alive[pq.top().id] == 0)
            pq.pop();
       while(!pq2.empty() && alive[pq2.top().id] == 0)
            pq2.pop();
       }
                   
    if(!pq.empty())
        ans[0] = pq.top().num;
    if(!pq2.empty())
        ans[1] = pq2.top().num;
                   
                
    return ans;
}
