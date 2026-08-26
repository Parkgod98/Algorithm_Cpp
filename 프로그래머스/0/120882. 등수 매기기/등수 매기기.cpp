#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


vector<int> solution(vector<vector<int>> score) {
    
    int sc[202] = {0};
    
    for (vector<int> &v : score){
        sc[v[0] + v[1]]++;
    }
    
    vector<int> ans(score.size(),0);
    int r = 1;
    
    int sz = score.size();
    int rank[202] = {0};
    
    for (int i = 200; i >= 0; --i){
        if(sc[i] > 0)
            rank[i] = r;
        while(sc[i] > 0){
            r++;
            sc[i]--;
        }
    }
    for (int i = 0; i < sz; ++i){
        ans[i] = rank[score[i][0] + score[i][1]];
    }
    
    return ans;
}