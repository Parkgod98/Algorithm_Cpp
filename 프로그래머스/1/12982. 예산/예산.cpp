#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(),d.end());
    
    int cnt = 0;
    for (int &n : d){
        if(budget - n >=0){
            budget -=n;
            ++cnt;
        }
    }
    return cnt;
}