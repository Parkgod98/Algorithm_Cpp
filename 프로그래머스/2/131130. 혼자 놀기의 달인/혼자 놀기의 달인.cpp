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
    int a = 0;
    int b = 0;
    int mx = 0;
    for (int i = 0; i < sz; ++i){
        vector<int> visited(sz,0);
        visited[i] = 1;
        a = DFS(i,cards,visited);
        // cout << a << " ";
        // cout << "\n";
        for (int j = i + 1; j < sz; ++j){
            if(!visited[j]){
                visited[j] = 1;
                b = DFS(j,cards,visited);
                // cout << b << " ";
                mx = max(mx,a*b);
            }
        }
        
        // cout << "\n\n";
    }
    
    return mx;
}