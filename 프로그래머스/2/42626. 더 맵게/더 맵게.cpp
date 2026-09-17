#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for (int &n : scoville)
        pq.push(n);
    
    int ans = 0;    
    while(1){
        int a,b;
        a = b = -1;
        if(!pq.empty()){
            a = pq.top();
            pq.pop();
        }
        if(!pq.empty()){
            b = pq.top();
            pq.pop();
        }
        if(a >= K){
            return ans;
        }
        if(b == -1)
            return -1;
        
        
        
        int n = a + b*2;
        pq.push(n);
        ++ans;
                
    }
    return 1;
}