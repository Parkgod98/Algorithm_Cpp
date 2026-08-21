#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

long long solution(string numbers) {
map<string, int> mp = {
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9}
};
    
    string word = "";
    long long ans = 0;
    for (char &c : numbers){
        word +=c;
        if(mp.find(word) != mp.end()){
            ans = ans*10 + (mp[word]);
            word.clear();
            continue;
        }
    }
    return ans;
}