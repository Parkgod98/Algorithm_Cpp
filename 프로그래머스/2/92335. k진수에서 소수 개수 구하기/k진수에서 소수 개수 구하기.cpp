#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int IsPrime(long long n){
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    for (long long i = 2; i * i <= n; ++i){
        if(n%i == 0)
            return 0;
    }
    
    return 1;
}

int solution(int n, int k) {
    string t = "";
    
    while(n!= 0){
        t += n%k + '0';
        n/=k;
    }
    reverse(t.begin(),t.end());
    
    vector<string> v;
    
    int prev;
    prev = -1;
    int idx;
    while(1){
        idx = t.find('0',prev+1);
        if(idx == string :: npos)
            break;
        
        string tt = t.substr(prev+1,idx-(prev+1));
        if(!tt.empty())
            v.push_back(tt);
        
        prev = idx;
    }
    if(prev +1 < t.size())
        v.push_back(t.substr(prev+1));
    
    int ans = 0;
    for (string &s : v){
        if(IsPrime(stoll(s)))
            ++ans;
    }
    return ans;
}