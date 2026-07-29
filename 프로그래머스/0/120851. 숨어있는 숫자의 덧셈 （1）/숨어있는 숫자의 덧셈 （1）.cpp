#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int res = 0;
    for (char &c : my_string){
        if(c >= '0' && c <= '9')
            res += c-'0';
    }
    return res;
}