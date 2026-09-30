#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int ans = 0;
    
    int end = 0;
    for (int &n : diffs)
        end = max(end,n);
    
    int start = 1;
    
    while(start <= end){
        int mid = (start + end)/2;
        
        long long t = 0;
        
        int sz = diffs.size();
        int time_prev = 0;
        for (int i = 0; i < sz; ++i){
            if(diffs[i] <= mid){
                t += times[i];
            }
            else{
                t += (diffs[i]-mid)*(time_prev+times[i]) + times[i];
            }
            time_prev = times[i];
            if(t > limit)
                break;
        }

        if(t > limit){
            start = mid+1;
        }
        else{
            ans = mid;
            end = mid-1;
        }
    }
    return ans;
}