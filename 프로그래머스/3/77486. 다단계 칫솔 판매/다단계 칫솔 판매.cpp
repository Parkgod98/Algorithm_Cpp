#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string,int> name_to_idx;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    
    int sz = enroll.size();
    for (int i = 0; i < sz; ++i)
        name_to_idx[enroll[i]] = i;
    
    
    vector<int> parent(sz,-1);
    
    for (int i = 0; i < sz; ++i){
        if(referral[i] == "-")
            continue;
        parent[i] = name_to_idx[referral[i]];
    }
    
    vector<int> ans(sz);
    
    for (int &n : amount)
        n*= 100;
    
    for (int i = 0; i < seller.size(); ++i){
        int cur = name_to_idx[seller[i]];
        int money = amount[i];
        while(cur != -1 && money > 0){
            int fee = money/10;
            ans[cur] += (money-fee);
            
            money = fee;
            cur = parent[cur];
        }

    }
    return ans;
}