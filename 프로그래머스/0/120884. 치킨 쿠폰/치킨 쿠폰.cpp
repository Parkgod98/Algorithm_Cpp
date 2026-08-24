#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int cnt = 0;
    
    while(chicken >=10){
        cnt += chicken/10;
        int remain = chicken%10;
        chicken /= 10;
        chicken += remain;
    }
    return cnt;
}
