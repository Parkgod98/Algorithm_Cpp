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
using namespace std;
// 2, 1, 1, 2, 3, 1, 2, 3, 1


bool IsCorrect( deque<char> &dq)
{
    stack<char> st;

    for( auto&c : dq )
    {
        if( !st.empty() && (( st.top() == '(' && c == ')' ) || ( st.top() == '{' && c == '}' ) || ( st.top() == '[' && c == ']' )) )
            st.pop();
        else
            st.push( c );
    }
    if( !st.empty() )
        return false;
    return true;
}

int solution( string s )
{
    int cnt = 0;
    deque<char> dq(s.begin(),s.end());
    for( int i = 0; i < s.size(); ++i )
    {
        if( IsCorrect( dq ) )
            ++cnt;
        char tmp = dq.front();
        dq.pop_front();
        dq.push_back( tmp );
    }
    return cnt;
}