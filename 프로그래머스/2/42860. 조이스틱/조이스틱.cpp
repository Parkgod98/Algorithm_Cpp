#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string name) {
    
    int ans = 0;
    for (char &c : name){
        if(c != 'A'){
            ans += min(c-'A',26-(c-'A'));
        }
    }
    
    int sz = name.size();
    int move = sz-1;
    
    for (int i = 0; i < sz; ++i){
        
        int j = i+1;
        while(j < sz && name[j] == 'A')
            ++j;
        
        int R = i;
        int L = sz - j;
        
        move = min(move,min(2*R + L, 2*L + R));
    }
    
    
    return ans + move;
}