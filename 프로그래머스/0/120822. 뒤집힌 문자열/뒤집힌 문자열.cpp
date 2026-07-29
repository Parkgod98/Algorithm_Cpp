#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    int sz = my_string.size();
    
    for (int i = 0; i < sz/2; ++i){
        char c = my_string[i];
        my_string[i] = my_string[sz - 1 - i];
        my_string[sz - 1- i] = c;
    }
    return my_string;
}