#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {

    int sz = is_prefix.size();
    if(sz > my_string.size())
        return 0;
    for (int i = 0; i < sz; ++i){
        if(is_prefix[i] != my_string[i])
            return 0;
    }
    return 1;

}