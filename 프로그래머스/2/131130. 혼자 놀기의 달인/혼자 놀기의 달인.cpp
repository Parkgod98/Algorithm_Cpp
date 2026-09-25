#include <string>
#include <vector>
#include <iostream>
using namespace std;

int DFS(int cur, vector<int> &v, vector<int> &visited){
    int sum = 1;
    
    if(!visited[v[cur]-1]){
        visited[v[cur]-1] = 1;
        sum += DFS(v[cur]-1,v,visited);
    }
    
    return sum;
}

int solution(vector<int> cards) {
    int sz = cards.size();
    
    vector<int> g_cnt(sz,0);
    int a = 0;
    int b = 0;
    int mx = 0;
    vector<int> visited(sz,0);
    
    int turn = 0;
    for (int i = 0; i < sz; ++i){
        if(!visited[i]){
            visited[i] = 1;
            int g = DFS(i,cards,visited);
            g_cnt[i] = g;
            if(a < g){
                b = a;
                a = g;
            }
            else if(a >= g && b < g){
                b = g;
            }
        }
    }
    
    return a*b;
}