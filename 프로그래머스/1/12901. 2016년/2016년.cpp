#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    int days[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    string day[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    
    int start = 0;
    
    for (int i = 1; i < a; ++i)
        start += days[i];
    start += (b-1);
    return day[start%7];
}