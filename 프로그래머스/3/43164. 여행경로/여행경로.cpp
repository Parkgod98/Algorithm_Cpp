#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string,vector<string>> graph;
vector<string> ans;

void DFS(string cur){
    while(!graph[cur].empty()){
        string nxt = graph[cur].back();
        graph[cur].pop_back();
        
        DFS(nxt);
    }
    
    ans.push_back(cur);
}


vector<string> solution(vector<vector<string>> tickets) {
    graph.clear();
    ans.clear();
    
    for (vector<string> &t : tickets){
        graph[t[0]].push_back(t[1]);
    }
    
    for (auto &it : graph){
        sort(it.second.begin(),it.second.end(),[&](string &a, string &b){
            return a > b;
        });
    }
    
    DFS("ICN");
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}