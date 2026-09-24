#include <vector>
#include <cmath>

using namespace std;

int cnt = 0;

void DFS(int n, vector<int> &v, int r){
    
    if(n == r){
        ++cnt;
        return;
    }
    
    for (int c = 0; c < n; ++c){
        
        bool f = true;
        for (int prev = 0; prev < r; ++prev){
            if(v[prev] == c){
                f = false;
                break;
            }
            if(v[prev] != -1 && abs(r-prev) == abs(v[prev] - c)){
                f = false;
                break;
            }
        }
        if(!f)
            continue;
        
        v[r] = c;
        DFS(n,v,r+1);
        v[r] = -1;
    }
}


int solution(int n) {
    
    cnt = 0;
    vector<int> v(n,-1);
    
    DFS(n,v,0);
    return cnt;
}