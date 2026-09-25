#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    int time[10000] = {0};
    int in[10000] = {0};
    int visited[10000] = {0};
    
    int basic_time = fees[0];
    int basic_money = fees[1];
    int unit_time = fees[2];
    int unit_money = fees[3];
    
    for(string &s : records){
        string t = s.substr(0,5);
        int num = stoi(s.substr(6,4));
        string inout = s.substr(11);
        
        int tm = stoi(t.substr(0,2))*60 + stoi(t.substr(3));
        
        if(inout == "IN"){
            in[num] = tm;
            visited[num] = 1;
        }
        else{
            time[num] += (tm-in[num]);
            in[num] = 0;
            visited[num] = 0;
        }
    }
    
    for (int i = 0; i <= 9999; ++i){
        if(in[i] != 0 || visited[i]){
            time[i] += (23*60) + 59 - in[i];
            in[i] = 0;
            visited[i] = 0;
        }
    }
    
    vector<int> ans;
    
    for (int i = 0; i <= 9999; ++i){
        if(time[i] > 0){
            if(time[i] <= basic_time)
                ans.push_back(basic_money);
            else{
                ans.push_back(basic_money + ceil(((double)time[i]-basic_time)/unit_time)*unit_money);
            }
        }
    }
    return ans;
}