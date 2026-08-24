#include <string>
#include <vector>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    
    vector<int> v;
    
    int sz = attendance.size();
    for (int i = 0; i < sz; ++i){
        if(attendance[i])
            v.push_back(i);
    }
    
    for (int i = 0; i < v.size(); ++i){
        for (int j = i+1; j < v.size(); ++j){
            if(rank[v[i]] > rank[v[j]]){
                int tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
    
    int sum = v[0]*10000 + v[1]*100 + v[2];
    return sum;
}