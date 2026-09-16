#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int remain[10] = {0};
    queue<int> q;
    for (int &n : priorities){
        q.push(n);
        remain[n]++;        
    }
    
    int cnt = 0;
    
    while(!q.empty()){
        int n = q.front();
        q.pop();
        location--;
        
        bool f = true;
        for (int i = n + 1; i <= 9; ++i){
            if(remain[i] > 0){
                f = false;
                break;
            }
        }
        
        if(f){
            ++cnt;
            remain[n]--;
            if(location == -1){
                return cnt;
            }
        }
        else{
            q.push(n);
            if(location == -1)
                location = q.size()-1;
        }
    }
    return 0;
}