#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string ans = "";
    
    for (int i = 0; i < s; ++i)
        ans += my_string[i];
    ans += overwrite_string;
    
    int sz = my_string.size();
    int o_sz = overwrite_string.size();
    for (int i = s+o_sz; i < sz; ++i)
        ans += my_string[i];
    return ans;
}