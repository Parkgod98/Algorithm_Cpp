#include <string>
#include <vector>

using namespace std;
int ans = 0;
void DFS(vector<int> &v, int tar, int sum, int idx){
    
    if(idx == v.size()){
        if(sum == tar)
            ++ans;
        return;
    }
    
    DFS(v,tar,sum+v[idx],idx+1);
    DFS(v,tar,sum-v[idx],idx+1);
    
}

int solution(vector<int> numbers, int target) {
    
    DFS(numbers,target,0,0);
    return ans;
}