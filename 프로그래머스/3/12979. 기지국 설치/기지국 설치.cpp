#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    
    int cnt = 0;
    
    int sz = stations.size();
    
    int start = -20000;
    int last = 400000000;
    
    int cur,nxt;
    
    cur = -w;
    nxt = stations[0];
    
    if(cur + w + 1 < nxt - w){
        int need = (nxt -w) - (cur+w+1);

        int coverage = 2*w + 1;

        if(need%coverage == 0)
            cnt += need/coverage;
        else
            cnt += (need/coverage)+1;
    }
    
    for (int i = 0; i < sz -1; ++i){
        cur = stations[i];
        nxt = stations[i+1];
        
        if(cur + w + 1 < nxt - w){
            int need = (nxt -w) - (cur+w+1);

            int coverage = 2*w + 1;

            if(need%coverage == 0)
                cnt += need/coverage;
            else
                cnt += (need/coverage)+1;
        }
    }
    
    cur = stations[sz-1];
    nxt = n+w+1;
    
    if(cur + w + 1 < nxt - w){
        int need = (nxt -w) - (cur+w+1);

        int coverage = 2*w + 1;

        if(need%coverage == 0)
            cnt += need/coverage;
        else
            cnt += (need/coverage)+1;
    }
    
    return cnt;
}