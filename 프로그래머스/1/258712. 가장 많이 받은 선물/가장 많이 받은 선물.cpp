#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    map<string,int> name_to_idx;
    
    int mx_size = friends.size();
    vector<vector<int>> exchange = vector<vector<int>>(mx_size,vector<int>(mx_size,0));
    for (int i = 0; i < friends.size(); ++i)
        name_to_idx[friends[i]] = i;
    
    for (string &s : gifts){
        int idx = s.find(' ');
        string A = s.substr(0,idx);
        string B = s.substr(idx+1);
        
        exchange[name_to_idx[A]][name_to_idx[B]]++;
        exchange[name_to_idx[B]][name_to_idx[B]]++;
    }
    
    vector<int> ans(mx_size,0);
    
    for (int i = 0; i < mx_size; ++i){
        for (int j = i+1; j < mx_size; ++j){
            if(exchange[i][j] > exchange[j][i])
                ans[i]++;
            else if(exchange[i][j] < exchange[j][i])
                ans[j]++;
            else{
                int i_jisoo = -exchange[i][i];
                int j_jisoo = -exchange[j][j];
                for (int k = 0; k < mx_size; ++k){
                    if(k!=i)
                        i_jisoo += exchange[i][k];
                    if(k!=j)
                        j_jisoo += exchange[j][k];
                }

                if(i_jisoo > j_jisoo)
                    ans[i]++;
                else if(i_jisoo < j_jisoo)
                    ans[j]++;

                    
            }
        }
    }
    
    int mx = 0;
    for (int i = 0; i < mx_size; ++i)
        mx = max(ans[i],mx);
    
    return mx;
    
    
}