#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int ans = 0;
    
    sort(score.begin(),score.end());
    int sz = score.size();
    for (int i = sz - 1; i >= 0; i -= m){
        if(i - m + 1 >= 0){
            ans += score[i - m + 1]*m;
        }
    }
    return ans;
}