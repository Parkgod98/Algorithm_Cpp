#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    int visited[1002] = {0};
    for (int &n : array)
        visited[n]++;
    
    int mx = -1;
    int ans = 0;
    int cnt2 = 0;
    for (int i = 0; i < 1000; ++i){
        if(visited[i] > mx){
            mx = visited[i];
            ans = i;
        }
        else if(visited[i] == mx){
            cnt2 = visited[i];
        }
    }
    
    if(mx == cnt2)
        return -1;
    return ans;
}