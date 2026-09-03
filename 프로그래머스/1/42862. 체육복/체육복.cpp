#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int cnt = n - lost.size();
    
    int reserved[33] = {0};
    for(int &r : reserve){
        reserved[r] = 1;
    }
    for (int &l : lost){
        reserved[l]--;
        if(reserved[l] == 0)
            ++cnt;
    }
    
    for (int i = 1; i <= 30; ++i){
        if(reserved[i] < 0){
            if(reserved[i-1] > 0){
                reserved[i-1] = 0;
                ++cnt;
            }
            else if(reserved[i+1] > 0){
                reserved[i+1] = 0;
                ++cnt;
            }
        }
    }
    return cnt;
}