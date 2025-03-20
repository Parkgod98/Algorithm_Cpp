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
using namespace std;

bool compare( vector<int> a, vector<int> b )
{
    return a.size() < b.size();
}

vector<int> solution( string s )
{
    vector<vector<int>> v;
    bool s_flag = false;
    int sum = 0;
    vector<int> tmp;
    for( int i = 1; i < s.size() - 1; ++i )
    {
        
        if( s[i] == '{' )
        {
            s_flag = true;
        }
        else if( s[i] == '}' )
        {
            tmp.push_back( sum );
            sum = 0;
            v.push_back( tmp );
            tmp.clear();
            s_flag = false;
        }
        else if( s_flag && s[i] == ',' )
        {
            tmp.push_back( sum );
            sum = 0;
        }
        else if( !s_flag && s[i] == ',' )
            continue;
        else
        {
            sum = sum * 10 + s[i] - '0';
        }
    }
    //for( int i = 0; i < v.size(); ++i )
    //{
    //    for( int j = 0; j < v[i].size(); ++j )
    //        cout << v[i][j] << " ";
    //    cout << "\n";
    //}

    sort( v.begin(), v.end(), compare );
    map<int, bool> mp;
    vector<int> ans;
    for( auto& vec : v )
    {
        for( int i = 0; i < vec.size(); ++i )
        {
            if( mp[vec[i]] )
                continue;
            else
            {
                ans.push_back( vec[i] );
                mp[vec[i]] = true;
            }
        }
    }
    //for( int i = 0; i < v.size(); ++i )
    //{
    //    for( int j = 0; j < v[i].size(); ++j )
    //        cout << v[i][j] << " ";
    //    cout << "\n";
    //}
    //for( int i = 0; i < ans.size(); ++i )
    //    cout << ans[i] << " ";

    return ans;
}
