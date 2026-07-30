#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    
    int len = is_suffix.size();
    int s_len = my_string.size();
    for (int i = s_len - len; i < s_len; ++i){
        if(my_string[i] != is_suffix[i - (s_len-len)])
            return 0;
    }
    return 1;
}