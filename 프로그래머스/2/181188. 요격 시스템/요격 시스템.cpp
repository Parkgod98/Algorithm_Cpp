#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    
    int cnt = 0;
    sort(targets.begin(),targets.end(),cmp);
    
    
    
    int sz = targets.size();
    int shot = -1;
    for (int i = 0; i < sz; ++i){
        int start = targets[i][0];
        int end = targets[i][1];
        if(start >= shot){
            ++cnt;
            shot = end;
        }
        else{
            continue;
        }
    }
    return cnt;
}