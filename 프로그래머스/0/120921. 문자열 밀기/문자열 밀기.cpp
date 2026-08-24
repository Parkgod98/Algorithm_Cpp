#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(string A, string B) {
    if(A==B)
        return 0;
    
    deque<char> dq;
    for (char &c : A)
        dq.push_back(c);
    int sz = A.size();
    
    for (int i = 0; i < sz; ++i){
        dq.push_front(dq.back());
        dq.pop_back();
        
        bool f = true;
        for (int k = 0; k < sz; ++k){
            if(dq[k] != B[k]){
                f = false;
                break;
            }
        }
        if(f){
            return i+1;
        }
    }
    
    return -1;
}