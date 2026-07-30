#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    for (char &c : myString){
        if(c >= 'a' && c <= 'z'){
            c -= 'a' - 'A';
        }
    }
    return myString;
}