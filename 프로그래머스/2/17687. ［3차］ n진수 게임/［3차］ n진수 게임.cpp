#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cctype>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
#include <stack>
#include <deque>
#include <list>
#include <unordered_set>
using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

// 진법 n, 미리 구할 숫자의 갯수 t, 게임에 참가하는 인원 m, 튜브의 순서 p

map<int, string> mp = {{0,"0"}, {1,"1"}, {2,"2"},{3,"3"},{4,"4"},{5,"5"},{6,"6"},{7,"7"},{8,"8"},{9,"9"},
    {10,"A"},{11,"B"},{12,"C"},{13,"D"},{14,"E"},{15,"F"}};

string Convert( int n, int sz )
{
    int s = 1;
    string tmp = "0";
    while( tmp.size() <= sz )
    {
        int k = s;
        string ss = "";
        while( k != 0 )
        {
            ss = mp[k%n] + ss;
            k /= n;
        }
        tmp += ss;
        ++s;
    }
    return tmp;
}
string solution( int n, int t, int m, int p )
{
    string plan = Convert( n, m * p * t );

    string res = "";
    int i = p - 1;
    while( res.size() < t )
    {
        res += plan[i];
        i += m;
    }
    return res;
}