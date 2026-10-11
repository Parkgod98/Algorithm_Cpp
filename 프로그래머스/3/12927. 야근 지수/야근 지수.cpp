#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long ans = 0;
    
    priority_queue<int> pq;
    for (int &n : works)
        pq.push(n);
    
    while(n > 0){
        int k = pq.top();
        if(k == 0)
            break;
        pq.pop();
        pq.push(k-1);
        n--;
    }
    
    while(!pq.empty()){
        ans += pq.top() * pq.top();
        pq.pop();
    }
        
    return ans;
}