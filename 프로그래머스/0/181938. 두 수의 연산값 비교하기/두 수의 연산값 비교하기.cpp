#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int res2 = 2*a*b;
    vector<int> num;
    
    while(b!=0){
        num.push_back(b%10);
        b/=10;
    }
    while(a!=0){
        num.push_back(a%10);
        a/=10;
    }
    int res1 = 0;
    
    int sz= num.size();
    for (int i = sz-1; i >=0; --i){
        res1 = res1*10 + num[i];
    }

    
    return res1 >= res2 ? res1 : res2;
}