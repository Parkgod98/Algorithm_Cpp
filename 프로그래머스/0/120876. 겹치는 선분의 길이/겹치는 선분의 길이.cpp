#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int visited[250] = {0};
    
    for (vector<int> &v : lines){
        int s = v[0];
        int e = v[1];
        
        visited[s+101]++;
        visited[e+101]--;
    }
    
    int diff = 0;
    int ans = 0;
    for (int i = 0; i < 250; ++i){
        diff += visited[i];
        
        if(diff >= 2)
            ++ans;
    }
    
    return ans;

}