#include <string>
#include <vector>
#include <cmath>

using namespace std;


/*

1 -> 0 
11011 -> 1
11011 11011 00000 11011 11011 - > 2
*/

long long Solve(long long n, long long l, long long r){
    
    long long sum = 0;
    if(n == 1){
        return 1;
    }
    long long one_sz = n/5;
    
    long long start = l / one_sz;
    long long end = r / one_sz;

    for (long long i = start; i <= end; ++i){
        if(i == 2)
            continue;
        if(i != start && i != end){
            sum += Solve(n/5,0,one_sz-1);
        }
        else if(i == start && i == end){
            sum += Solve(n/5,l%one_sz,r%one_sz);
        }
        else if(i == start){
            sum += Solve(n/5,l%one_sz,one_sz-1);
        }
        else if(i == end){
            sum += Solve(n/5,0,r%one_sz);
        }
    }
    
    return sum;
    
}

int solution(int n, long long l, long long r) {
    
    long long s = pow(5,n);
    long long ans = Solve(s,l-1,r-1);
    return ans;
}