#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int sum = 0;
    
    for (int i = left; i <= right; ++i){
        
        int r = sqrt(i);
        
        if(r*r == i)
            sum -= i;
        else
            sum += i;
    }
    return sum;
}