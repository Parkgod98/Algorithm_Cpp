#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int visited[250] = {0};
    
    for (vector<int> &v : lines){
        int s = v[0];
        int e = v[1];
        
        for (int i = s +101; i <= e+101; ++i)
            visited[i] +=1;
        visited[e+101] -=1;
    }
    
    int cnt = 0;
    for (int i = 0; i < 250; ++i)
        if(visited[i] >= 2)
            ++cnt;
    

    
    return cnt;

}