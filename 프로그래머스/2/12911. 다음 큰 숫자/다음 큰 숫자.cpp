#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int cn = n;
    int cnt = 0;
    while(cn != 0){
        cnt += cn%2;
        cn/=2;
    }
    
    int start = n+1;
    while(1){
        
        int ccnt = 0;
        int k = start;
        while(k != 0){
            ccnt += k%2;
            k/=2;
        }
        if(ccnt == cnt)
            return start;
        ++start;
    }
    
}