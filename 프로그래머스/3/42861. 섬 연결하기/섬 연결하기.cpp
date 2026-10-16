#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int parent[102] = {0};
struct cmp{
    bool operator()(const vector<int> &a, const vector<int> &b) const{
        return a[2] < b[2];
    }
};

int find_parent(int n){
    if(parent[n] != n)
        return parent[n] = find_parent(parent[n]);
    return n;
}

bool union_parent(int a, int b){
    int pa = find_parent(a);
    int pb = find_parent(b);
    
    if(pa == pb)
        return false;
    
    if(pa > pb)
        parent[pb] = pa;
    else
        parent[pa] = pb;
    
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    for (int i = 0; i < n; ++i){
        parent[i] = i;
    }
    
    sort(costs.begin(),costs.end(),cmp());
    
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < costs.size(); ++i){
        int a = costs[i][0];
        int b = costs[i][1];
        
        if(union_parent(a,b)){
            ans += costs[i][2];
            ++cnt;
        }
        if(cnt == n - 1)
            break;
    }
    return ans;
}