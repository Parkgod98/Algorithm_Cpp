#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void Make(vector<int> &v, int num, int sz, int tar){
    if(sz == tar){
        v.push_back(num);
        return;
    }
    if(num!=0)
        Make(v,num*10,sz+1,tar);
    Make(v,num*10+5,sz+1,tar);
}

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    vector<int> all_cases;
    
    for (int i = 1; i <= 6; ++i){
        Make(all_cases,0,0,i);
    }
    
    for (int i = 0; i < all_cases.size(); ++i){
        if(all_cases[i] >= l && all_cases[i] <= r)
            answer.push_back(all_cases[i]);
        else if(all_cases[i] > r)
            break;
    }
    if(answer.size() == 0)
        return vector<int>(1,-1);
    return answer;
}