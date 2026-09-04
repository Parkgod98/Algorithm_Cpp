#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int ans = 0;
    int sz = schedules.size();
    
    for (int i = 0; i < sz; ++i){
        int s = startday;
        
        vector<int> &v = timelogs[i];
        
        int st = schedules[i]/100;
        int sm = schedules[i]%100;
        
        int em = sm + 10;
        int et = st + (em/60);
        em %= 60;
        
        int deadline = et*100 + em;
        
        bool f = true;
        for (int &n : v){
            if(s != 6 && s!= 7){
                if(n > deadline){
                    f = false;
                    break;
                }
            }
            ++s;
            if(s == 8)
                s = 1;
        }
        if(f)
            ++ans;
    }
    return ans;
}