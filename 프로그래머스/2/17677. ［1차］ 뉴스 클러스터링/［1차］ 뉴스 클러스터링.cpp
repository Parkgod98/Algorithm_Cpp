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

int solution( string str1, string str2 )
{
    vector<string> v1, v2;
    unordered_set<string> u_set;
    for( int i = 0; i < str1.size() - 1; ++i )
    {
        string s = str1.substr( i, 2 );
        if( !isalpha( s[0] ) || !isalpha( s[1] ) )
            continue;
        transform( s.begin(), s.end(), s.begin(), ::tolower );
        v1.push_back( s );
        u_set.insert( s );
    }
    for( int i = 0; i < str2.size() - 1; ++i )
    {
        string s = str2.substr( i, 2 );
        if( !isalpha( s[0] ) || !isalpha( s[1] ) )
            continue;
        transform( s.begin(), s.end(), s.begin(), ::tolower );
        v2.push_back( s );
        u_set.insert( s );
    }

    unordered_map<string, int> mp1, mp2;
    for( int i = 0; i < v1.size(); ++i )
    {
        mp1[v1[i]]++;
    }
    for( int i = 0; i < v2.size(); ++i )
    {
        mp2[v2[i]]++;
    }

    int gyo = 0;
    int hap = 0;
    for(const string& s : u_set )
    {
        if( mp1[s] && mp2[s] )
        {
            gyo += min( mp1[s], mp2[s] );
            hap += max( mp1[s], mp2[s] );
        }
        else if( mp1[s] )
        {
            hap += mp1[s];
        }
        else if( mp2[s] )
        {
            hap += mp2[s];
        }
    }
    int jacade = (( double )gyo / hap)*65536.0;
    if( gyo == 0 && hap == 0 )
        return 65536;

    return jacade;
}