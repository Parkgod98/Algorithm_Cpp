#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    
    int sum = 0;
    
    while(n!= 0){
        int k = (n/a)*b; 
        sum += (n/a)*b;
        n %=a;
        n += k;
        if(k == 0)
            break;
    }
    return sum;
}