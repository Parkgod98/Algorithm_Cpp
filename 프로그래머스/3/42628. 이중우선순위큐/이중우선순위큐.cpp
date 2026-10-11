#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> pq2;
    
    map<int,int> mp;
    for (string &s : operations){
        char com = s[0];
        
        string tar = s.substr(2);
        int k = stoi(tar);
        if(com == 'I'){
            pq.push(k);
            pq2.push(k);
            mp[k]++;
        }
        else{
            if(k == 1){
                if(!pq.empty() && mp[pq.top()] > 0){
                    mp[pq.top()]--;
                    pq.pop();
                }

            }
            else{
                if(!pq2.empty() && mp[pq2.top()] > 0){
                    mp[pq2.top()]--;
                    pq2.pop();
                }

            }
            while(!pq.empty() && mp[pq.top()] == 0){
                pq.pop();
            }
            while(!pq2.empty() && mp[pq2.top()] == 0){
                pq2.pop();
            }
        }
    }
    
    vector<int> ans(2);
    if(!pq.empty())
        ans[0] = pq.top();
    if(!pq2.empty())
        ans[1] = pq2.top();
    return ans;
}