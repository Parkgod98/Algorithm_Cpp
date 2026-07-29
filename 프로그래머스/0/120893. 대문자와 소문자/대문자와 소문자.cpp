#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    for (char &c : my_string){
        if(c >= 'A' && c <= 'Z')
            c -= 'A' - 'a';
        else
            c += 'A' - 'a';
    }
    return my_string;
}