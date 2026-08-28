#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int r = 0;
    int c = 0;
    for (vector<int> &v : sizes){
        if(v[0] > v[1])
            swap(v[0],v[1]);
        
        r = max(v[0],r);
        c = max(v[1],c);
    }
    
    return r*c;
}