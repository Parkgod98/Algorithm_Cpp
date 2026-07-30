#include <string>
#include <vector>

using namespace std;

int solution(string n_str) {
    int n = 0;
    for (char &c : n_str){
        n = n*10 +(c-'0');
    }
    return n;
}