#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int ans = 0;
    int tsz = t.size();
    int psz = p.size();
    for (int i = 0; i <= tsz-psz; ++i){
        
        bool f = false;
        for (int j = 0; j < psz; ++j){
            if(t[i+j] < p[j]){
                f = true;
                break;
            }
            else if(t[i+j] == p[j]){
                f = true;
            }
            else{
                f = false;
                break;
            }
        }
        if(f){
            ++ans;
        }
    }
    return ans;
}