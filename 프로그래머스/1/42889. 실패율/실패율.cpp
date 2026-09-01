#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<int> stage_num(N+2,0);
    for (int &n : stages)
        stage_num[n]++;
    
    vector<int> prefix_stage(N+3,0);
    for (int i = N + 1; i >= 1; --i){
        prefix_stage[i] = prefix_stage[i+1] +stage_num[i];
    }
    
    vector<double> failure(N+2,0);
    for (int i = N+1; i >= 1; --i){
        if(prefix_stage[i] != 0)
            failure[i] = (double)stage_num[i]/prefix_stage[i];
    }
    
    vector<int> ans;
    for (int i = 1; i <= N; ++i)
        ans.push_back(i);
    
    sort(ans.begin(),ans.end(),[&](int a, int b){
        if(failure[a] != failure[b])
            return failure[a] > failure[b];
        return a < b;
    });
    return ans;
}