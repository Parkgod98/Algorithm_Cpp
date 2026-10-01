#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> v;
int anss;
void Comb(int n, int k, int depth, int idx, vector<vector<int>> &q, vector<int> &ans, vector<int> &num_list){
    
    if(depth == k){
        bool f = true;
        for (int i = 0; i < q.size(); ++i){
            int cnt = 0;
            for (int j = 0; j < 5; ++j){
                for (int k = 0; k < 5; ++k){
                    if(q[i][k] == v[j]){
                        ++cnt;
                        break;
                    }
                }
            }
            if(cnt != ans[i]){
                f = false;
                break;
            }
        }
        if(f){
            ++anss;
        }
        
        return;
    }
    
    
    for (int i = idx; i < num_list.size(); ++i){
        v.push_back(num_list[i]);
        Comb(n,k,depth+1,i+1,q,ans,num_list);
        v.pop_back();
    }
    
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    anss = 0;
    vector<int> num_list;
    for (int i = 1; i <= n; ++i)
        num_list.push_back(i);
    
    Comb(num_list.size(),5,0,0,q,ans,num_list);
    return anss;
}