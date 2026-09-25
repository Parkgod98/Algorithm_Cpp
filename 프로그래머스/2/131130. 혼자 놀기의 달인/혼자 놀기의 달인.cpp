#include <string>
#include <vector>
#include <iostream>
using namespace std;

int DFS(int cur, vector<int> &v, vector<int> &visited, int t){
    int sum = 1;
    
    if(visited[v[cur]-1] != t){
        visited[v[cur]-1] = t;
        sum += DFS(v[cur]-1,v,visited,t);
    }
    
    return sum;
}

int solution(vector<int> cards) {
    int sz = cards.size();
    int a = 0;
    int b = 0;
    int mx = 0;
    vector<int> visited(sz,0);
    
    int turn = 0;
    for (int i = 0; i < sz; ++i){
        ++turn;
        visited[i] = turn;
        a = DFS(i,cards,visited,turn);
        for (int j = i + 1; j < sz; ++j){
            if(visited[j] != turn){
                visited[j] = turn;
                b = DFS(j,cards,visited,turn);
                mx = max(mx,a*b);
            }
        }
    }
    
    return mx;
}