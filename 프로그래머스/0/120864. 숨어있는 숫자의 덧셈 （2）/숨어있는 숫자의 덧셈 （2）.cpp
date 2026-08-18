#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int solution(string my_string) {
    string word = "";
    int sum = 0;
    for (char &c : my_string){
        if(!isdigit(c) && !word.empty()){
            sum += stoi(word);
            word.clear();
        }
        else if(isdigit(c)){
            word += c;
        }
    }
    if(!word.empty())
        sum += stoi(word);
    return sum;
}