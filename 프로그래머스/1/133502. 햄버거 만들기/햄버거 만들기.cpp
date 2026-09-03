#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> ingredient) {
    int cnt = 0;
    deque<int> dq;
    int state = 0;
    for (int &n : ingredient){
        if(!dq.empty()){
            if(dq.back() == 1 && n == 2){
                dq.push_back(n);
                state = 1;
            }
            else if(dq.back() == 2 && n == 3 && state == 1){
                dq.push_back(n);
                state = 2;
            }
            else if(dq.back() == 3 && n == 1 && state == 2){
                for (int i = 0; i < 3; ++i)
                    dq.pop_back();
                int cur = dq.size() - 1;
                
                if(cur -2 >= 0 && dq[cur-2] == 1 && dq[cur-1] == 2 && dq[cur] == 3)
                    state = 2;
                else if(cur-1 >= 0 && dq[cur-1] == 1 && dq[cur] == 2)
                    state = 1;
                else
                    state = 0;
                ++cnt;
            }
            else{
                state = 0;
                dq.push_back(n);
            }
        }
        else{
            state = 0;
            dq.push_back(n);
        }
    }
    return cnt;
}