#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    vector<string> v;
    
    int sz = my_string.size();
    string word = "";
    for (int i = 0; i < sz; ++i){
        if(isdigit(my_string[i])){
            word += my_string[i];
        }
        else if(isspace(my_string[i])){
            if(!word.empty()){
                v.push_back(word);
                word.clear();
            }
            continue;
        }
        else{
            word += my_string[i];
            v.push_back(word);
            word.clear();        }
    }
    if(!word.empty())
        v.push_back(word);
    
    int sum = stoi(v[0]);
    
    sz = v.size();
    char op = ' ';
    for (int i = 1; i < sz; ++i){
        if(v[i] == "+"){
            op = '+';
        }
        else if(v[i] == "-"){
            op = '-';
        }
        else{
            int num = stoi(v[i]);
            if(op == '+'){
                sum += num;
            }
            else{
                sum -= num;
            }
        }
    }
    return sum;
}