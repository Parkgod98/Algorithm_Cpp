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
using namespace std;

vector<int> solution( vector<int> answers )
{
    vector<vector<int>> v = { {1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5} };
    vector<int> mp = { -1,0,0,0 };
    for( int i = 0; i < answers.size(); ++i )
    {
        for( int j = 0; j < v.size(); ++j )
        {
            if( v[j][i % v[j].size()] == answers[i] )
                mp[j + 1]++;
        }
    }
    int mx = *max_element( mp.begin(), mp.end() );
    vector<int> ans;
    for( int i = 1; i < 4; ++i )
    {
        if( mx == mp[i] )
            ans.push_back( i );
    }
    return ans;
}