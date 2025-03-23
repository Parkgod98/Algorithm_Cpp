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

vector<string> v;
char c[5] = { 'A','E','I','O','U' };

void DFS(string &s)
{
    if( s.size() == 5 )
        return;
    for( int i = 0; i < 5; ++i )
    {
        s += c[i];
        v.push_back(s);
        DFS(s);
        s.pop_back();
    }
}

int solution( string word )
{


    string ans = "";
    DFS( ans );
    for( int i = 0; i < 20; ++i )
        cout << v[i] << "\n";
    for( int i = 0; i < v.size(); ++i)
    {
        if( word == v[i] )
            return i + 1;
    }
}