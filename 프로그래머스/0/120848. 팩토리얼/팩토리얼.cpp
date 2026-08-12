#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int res = 0;
    for (int i = 1; i <=10; ++i){
        answer *= i;
        if(answer >= n){
            res = i;
            break;
        }
    }
    if(answer == n)
        return res;
    else
        return res-1;
}