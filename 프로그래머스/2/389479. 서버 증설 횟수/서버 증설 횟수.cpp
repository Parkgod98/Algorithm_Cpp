#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int ans = 0;
    int time = 0;
    queue<int> q;
    for (int &n : players){
        while(!q.empty()){
            if(time - q.front() >= k){
                q.pop();
            }
            else
                break;
        }
        while(n >= (q.size()+1)*m){
            q.push(time);
            ++ans;
        }
        ++time;
    }
    
    return ans;
}