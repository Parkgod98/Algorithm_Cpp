#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> ans;
    
    int arr[46] = {0};
    for (int &n : lottos){
        arr[n]++;
    }
    
    int cnt = 0;
    for (int &n : win_nums)
        if(arr[n] >= 1)
            ++cnt;
    
    int mx_cnt = min(6,cnt+arr[0]);
    
    ans.push_back(7-mx_cnt);
    ans.push_back(7-cnt);
    for (int i = 0; i < 2; ++i){
        if(ans[i] >=6)
            ans[i] = 6;
    }
    
    return ans;
}