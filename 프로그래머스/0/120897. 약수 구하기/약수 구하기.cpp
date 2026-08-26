#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> ans;
    
    int visited[10001] = {0};
    
    for (int i = 1; i *i <= n; ++i){
        if(n%i == 0){
            visited[i] = visited[n/i] = 1;
        }
    }
    for (int i = 1; i <= n; ++i){
        if(visited[i])
            ans.push_back(i);
    }

    return ans;
}