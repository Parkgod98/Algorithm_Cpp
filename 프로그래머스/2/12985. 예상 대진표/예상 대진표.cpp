#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    
    int cnt = 1;
    while(a!=0 && b != 0){
        if(a/2 != b/2 && ((a+1 == b) || (a == b+1))){
            return cnt;
        }
        if(a%2 == 1)
            ++a;
        if(b%2 == 1)
            ++b;
        a/=2;
        b/=2;
        ++cnt;
    }

    return cnt;
}