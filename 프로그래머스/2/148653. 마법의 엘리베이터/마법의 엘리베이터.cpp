#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    
    int cnt = 0;
    while(storey != 0){
        
        int cur = storey%10;
        if(cur <=4){
            cnt += cur;
            storey -= cur;
        }
        else if(cur >= 6){
            cnt += (10-cur);
            storey += (10-cur);
        }
        else{
            int front = storey%100;
            front /= 10;
            if(front >= 5){
                cnt += (10-cur);
                storey += (10-cur);
            }
            else{
                cnt += cur;
                storey -= cur;
            }
        }
        storey /= 10;
    }
    
    return cnt;
}