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

vector<int> solution( vector<int> numbers )
{
    vector<int> ans(numbers.size());
    stack<pair<int, int>> st;

    for( int i = 0; i < numbers.size(); ++i )
    {
        while( !st.empty() && numbers[i] > st.top().first )
        {
            ans[st.top().second] = numbers[i];
            st.pop();
        }
        st.push( { numbers[i],i } );
    }
    while( !st.empty() )
    {
        ans[st.top().second] = -1;
        st.pop();
    }

    return ans;
}
