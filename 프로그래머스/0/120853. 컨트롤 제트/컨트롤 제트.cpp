#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    vector<string> v;
    
    string word = "";
    for (char &c : s){
        if(c == ' '){
            v.push_back(word);
            word.clear();
            continue;
        }
        word += c;
    }
    v.push_back(word);
    
    int sum = 0;
    int prev = 0;
    for (string &s : v){
        if(s == "Z"){
            sum -= prev;
        }
        else{
            int n = stoi(s);
            sum += n;
            prev = n;
        }
    }
    return sum;
}