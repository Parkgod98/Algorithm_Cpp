#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int ans = 0;
    
    priority_queue<int> pq;
    for (int n : score)
        pq.push(n);
    
    int cnt = 0;
    while(!pq.empty()){
        int k = pq.top();
        pq.pop();
        ++cnt;
        if(cnt == m){
            ans += k*m;
            cnt = 0;
        }
    }

    return ans;
}