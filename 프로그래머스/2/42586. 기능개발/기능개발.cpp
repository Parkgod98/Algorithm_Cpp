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

vector<int> solution( vector<int> progresses, vector<int> speeds )
{

    vector<int> days( progresses.size() );
    for( int i = 0; i < progresses.size(); ++i )
        days[i] = ceil((100.0 - progresses[i])/speeds[i]); // 7 3 9

    stack<int> st;
    vector<int> ans;
    int cnt = 0;
    for( int i = 0; i < days.size(); ++i )
    {
        if( !st.empty() && st.top() < days[i] )
        {
            st.pop();
            ans.push_back( cnt );
            cnt = 0;
            st.push( days[i] );
        }
        else if (st.empty())
        {
            st.push( days[i] );
        }
        ++cnt;
    }
    if( !st.empty() )
        ans.push_back( cnt );

    return ans;
}