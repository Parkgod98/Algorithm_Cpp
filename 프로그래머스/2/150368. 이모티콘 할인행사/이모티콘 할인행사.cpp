#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v;
int mx;
double mx_money;

void Comb(int k, int depth, vector<int> &emoticons, vector<vector<int>> &users){
    
    if(k == depth){
        int imtee_plus = 0;
        int total_benefit = 0;
        
        for (vector<int> &u : users){
            int limit_sail = u[0];
            int posit = u[1];
            
            double cur = 0;
            int sz = emoticons.size();
            for (int i = 0; i < sz; ++i){
                double price = (1- (double)v[i]/100)*emoticons[i];
                
                if(limit_sail <= v[i]){
                    cur += price;
                }
            }
            
            if(cur >= posit){
                ++imtee_plus;
            }
            else{
                total_benefit += cur;
            }
        }
        
        if(mx < imtee_plus){
            mx = imtee_plus;
            mx_money = total_benefit;
        }
        else if(mx == imtee_plus && mx_money < total_benefit){
            mx_money = total_benefit;
        }
        return;
    }
    
    
    for (int i = 10; i <= 40; i += 10){
        v.push_back(i);
        Comb(k,depth+1,emoticons,users);
        v.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> ans(2);
    mx = mx_money = 0;
    int sz = emoticons.size();
    
    Comb(sz,0,emoticons,users);
    
    ans[0] = mx;
    ans[1] = mx_money;
    return ans;
}