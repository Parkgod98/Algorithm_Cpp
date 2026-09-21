#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq;
    
    int sz = enemy.size();
    int ans = 0;
    pq.push(0);
    for (int i = 0; i < sz; ++i){
        if(n - enemy[i] >= 0){
            n -= enemy[i];
            pq.push(enemy[i]);
        }
        else{
            if(k> 0){
                if(pq.top() > enemy[i]){
                    n += pq.top();
                    pq.pop();
                    n -= enemy[i];
                    pq.push(enemy[i]);
                }
                --k;
            }
            else{
                ans = i;
                break;
            }
        }
    }
    
    if(ans == 0)
        ans = sz;
    return ans;
}