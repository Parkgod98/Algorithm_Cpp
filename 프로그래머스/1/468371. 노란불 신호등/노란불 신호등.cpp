#include <string>
#include <vector>
#include <iostream>

using namespace std;

int GetGCD(int a, int b){
    while(a%b != 0){
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}

int solution(vector<vector<int>> signals) {
    int sz = signals.size();
    
    int mx_term = 1;
    
    int one = signals[0][0] + signals[0][1] + signals[0][2];
    int two = signals[1][0] + signals[1][1] + signals[1][2];
    int lcm = (one * two) / (GetGCD(one,two));
    
    for (int i = 2; i < sz; ++i){
        int cycle = signals[i][0] + signals[i][1] + signals[i][2];
        lcm = (lcm * cycle) / (GetGCD(lcm,cycle));
        
    }
    
    vector<int> arr(lcm+1,0);
    
    for (vector<int> &v : signals){
        int start = v[0]+1;
        int interval = v[0] + v[1] + v[2];
        
        for (int i = start; i < lcm; i += interval){
            for (int j = i; j < i+v[1] && j < lcm; ++j)
                arr[j]++;
        }
    }
    
    for (int i = 0; i < lcm; ++i){
        if(arr[i] == sz)
            return i;
    }
    return -1;
}