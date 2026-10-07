#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {

    int prev = 0;
    int idx = 0;

    long long mx = -9999999999;
    long long mn = 9999999999;
    while (idx < s.size()) {
        idx = s.find(' ',prev);
        if (idx == string::npos) {
            idx = s.size();
        }
        int k = stoi(s.substr(prev, idx - prev));

        if (mx < k) {
            mx = k;
        }
        if (mn > k)
            mn = k;
        prev = idx + 1;
    }

    string ans = "";
    ans += to_string(mn) + " " + to_string(mx);
    return ans;
}