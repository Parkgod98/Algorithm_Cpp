#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {
    string answer = "";
    
    int len = (e-s +1);
    for (int i = 0; i < len/2; ++i){
        char tmp = my_string[i+s];
        my_string[i+s] = my_string[len -i + s-1];
        my_string[len -i -1 + s] = tmp;
    }
    return my_string;
}