#include <string>
#include <vector>

using namespace std;

bool IsPrime(int n){
    
    for (int i = 2; i *i <= n; ++i){
        if(n%i == 0)
            return false;
    }
    return true;
}

int GetNextPrime(int n){
    
    while(!IsPrime(n)){
        ++n;
    }
    return n;
}

vector<int> solution(int n) {
    vector<int> ans;
    
    int prime = 2;
    while(n != 1){
        bool f = false;
        while(n%prime == 0){
            n/=prime;
            f = true;
        }
        if(f)
            ans.push_back(prime);
        prime = GetNextPrime(prime+1);
    }
    return ans;
}