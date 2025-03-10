#include <string>
#include <vector>

using namespace std;

string solution( int a, int b ) {
    int days = 5;
    vector<int> month = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
    vector<string> ans = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
    for (int i = 1; i < a; ++i ){
        days += month[i];
    }
    days += b-1;
    return ans[days%7];
}
