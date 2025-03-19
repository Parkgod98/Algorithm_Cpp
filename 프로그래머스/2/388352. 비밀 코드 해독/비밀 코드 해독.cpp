#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cctype>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <cmath>
using namespace std;

int solution( int n, vector<vector<int>> q, vector<int> ans )
{
    vector<int> mask(n);
    int anser = 0;
    for (int i = 0; i <5; ++i){
        mask[n-i -1] = 1;
    }
    do{
        bool flag = true;
        for (int i = 0 ; i < q.size(); ++i ){
            if(ans[i] != (mask[q[i][0]-1] + mask[q[i][1]-1] + mask[q[i][2]-1] + mask[q[i][3]-1] + mask[q[i][4]-1] )){
                flag = false;                     
                break;
            }
        }
        if(flag)
            anser++;
        
    }while(next_permutation(mask.begin(),mask.end()));
    
    
    return anser;
}