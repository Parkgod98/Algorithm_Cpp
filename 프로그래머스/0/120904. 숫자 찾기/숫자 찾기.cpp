#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    string s = to_string(num);
    
    int sz = s.size();
    
    for (int i = 0; i < sz; ++i){
        if(s[i] - '0' == k)
            return i+1;
    }
    return -1;
}