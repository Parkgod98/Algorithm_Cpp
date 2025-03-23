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

string Convert( int n, int k )
{
    string ans = "";

    while( n != 0 )
    {
        ans += to_string( n % k );
        n /= k;
    }
    reverse( ans.begin(), ans.end() );
    
    return ans;
}
// 211020101011입니다.
vector<string> split( string& s, string sep )
{
    vector<string> res;

    int i = s.find( sep );
    int start = 0;
    while( i != string::npos )
    {
        string token = s.substr( start, i-start );
        if(token.size() !=0 )
            res.push_back( token );
        start = i + 1;
        i = s.find( sep, start );
    }
    if(start != s.size() )
        res.push_back( s.substr( start ) );

    return res;
}

bool IsPrime( long long n )
{
    if( n < 2 )
        return false;
    for( long long i = 2; i <= sqrt( n ); ++i )
    {
        if( n%i == 0 )
            return false;
    }
    return true;
}

int solution( int n, int k )
{
    string pas = Convert( n, k );

    int cnt = 0;
    vector<string> s_v = split( pas, "0" );

    for( string& s : s_v )
    {
        if( IsPrime( stoll( s ) ) )
            ++cnt;
    }

    return cnt;
}