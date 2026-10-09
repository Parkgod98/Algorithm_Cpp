#include <string>
#include <vector>
#include <set>

using namespace std;

int parent[202] = {0};

int find_parent(int n){
    if(parent[n] != n)
        return parent[n] = find_parent(parent[n]);
    return n;
}

void union_parent(int a, int b){
    int pa = find_parent(a);
    int pb = find_parent(b);
    
    if(pa == pb)
        return;
    
    if(pa > pb)
        parent[pa] = pb;
    else
        parent[pb] = pa;
}

int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; ++i)
        parent[i] = i;
    
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            if(computers[i][j] == 1){
                union_parent(i,j);
            }
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; ++i){
        if(find_parent(i) == i){
            ++cnt;
        }
    }
    
    return cnt;
}