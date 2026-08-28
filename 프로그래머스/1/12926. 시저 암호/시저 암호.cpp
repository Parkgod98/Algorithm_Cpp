#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for (char &c : s){
        if(islower(c)){
            c = (c - 'a' +n)%26 +'a';
        }
        else if(isupper(c)){
            c = (c - 'A' +n)%26 +'A';
        }
    }
    return s;
}