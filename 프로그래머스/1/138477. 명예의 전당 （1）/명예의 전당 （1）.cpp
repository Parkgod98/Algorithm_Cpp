#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> ans;
    priority_queue<int,vector<int>, greater<int>> pq;
    
    for (int &n :score){
        pq.push(n);
        if(pq.size() > k)
            pq.pop();
        
        ans.push_back(pq.top());
    }
    return ans;
}