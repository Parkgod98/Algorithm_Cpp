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
        string &s = seller[i];
        
        int idx = name_to_idx[s];
        int am = amount[i];
        if(parent[idx] == -1){
            int bbozzi = am * 0.1;
            if(bbozzi < 1)
                ans[idx] += am;
            else
                ans[idx] += (am-bbozzi);
        }
        else{
            int bbozzi = am * 0.1;
            while(parent[idx] != -1){
                bbozzi = am * 0.1;
                
                // cout << enroll[idx] << " mine : " << mine << " bbozzi : " << bbozzi << "\n"; 
                if(bbozzi < 1){
                    ans[idx] += am;
                    break;
                }
                ans[idx] += am-bbozzi;
                am = bbozzi;
                idx = parent[idx];
            }
            if(parent[idx] == -1){
                bbozzi = am * 0.1;
                if(bbozzi < 1)
                    ans[idx] += am;
                else
                    ans[idx] += am-bbozzi;
            }
        }

    }
    return ans;
}