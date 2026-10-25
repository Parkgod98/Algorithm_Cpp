#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    
    if(a[0] != b[0])
        return a[0] > b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> scores) {
    int w1 = scores[0][0];
    int w2 = scores[0][1];
    int wanho = w1 + w2;

    int rank[200002] = {0};
    
    sort(scores.begin(),scores.end(),cmp);
    
    int smx = 0;
    for (vector<int> &v : scores){
        smx = max(smx,v[1]);
        if(v[1] < smx)
            continue;
        
        if(v[0] > w1 && v[1] > w2)
            return -1;
        rank[v[0] + v[1]]++;
    }
    
    int r = 1;
    for (int i = 200000; i >= 0; --i){
        if(i == wanho){
            return r;
        }
        r += rank[i];
    }
    return -1;
}