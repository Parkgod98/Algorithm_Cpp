#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    for (vector<int> &v : routes){
        v[0] += 30000;
        v[1] += 30000;
    }
    
    sort(routes.begin(),routes.end(),cmp);
    
    int cnt = 0;
    
    int cur = -1;
    for (vector<int> &v : routes){
        if(cur < v[0]){
            ++cnt;
            cur = v[1];
        }
    }
    return cnt;
}