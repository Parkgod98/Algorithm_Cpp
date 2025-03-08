#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (char c : s) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + n) % 26 + base;
        }
        answer += c;
    }
    return answer;
}