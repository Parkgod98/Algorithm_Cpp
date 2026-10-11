#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

void DFS(int &ans, int cur, vector<vector<int>> &v, int tar, int depth, vector<vector<int>> &visited){
    if(cur == tar){
        ans = min(ans,depth);
        return;
    }
    
    for (int i = 0; i < v.size(); ++i){
        if(i != cur && visited[cur][i] == 0 && v[cur][i] == 1){
            visited[cur][i] = 1;
            DFS(ans,i,v,tar,depth+1,visited);
            visited[cur][i] = 0;
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    int idx = -1;
    int sz = words.size();
    
    for (int i = 0; i < sz; ++i){
        if(words[i] == target){
            idx = i;
            break;
        }
    }
    if(idx == -1)
        return 0;
    
    vector<string> w;
    w.push_back(begin);
    for (string &s : words)
        w.push_back(s);
    
    ++idx;
    
    vector<vector<int>> v = vector<vector<int>>(sz + 1,vector<int>(sz+1)); 
    
    for (int i = 0; i < w.size(); ++i){
        for (int j = 0; j < w.size(); ++j){
            if(i == j)
                continue;
            
            int diff = 0;
            for (int k = 0; k < w[i].size(); ++k){
                if(w[i][k] != w[j][k])
                    ++diff;
            }
            if(diff == 1){
                v[i][j] = v[j][i] = 1;
            }
        }
    }
    
    int ans = 999999999;
    
    vector<vector<int>> visited(sz+1,vector<int>(sz+1));
    DFS(ans,0,v,idx,0,visited);
    
    if(ans == 999999999)
        return 0;
    
    return ans;
}