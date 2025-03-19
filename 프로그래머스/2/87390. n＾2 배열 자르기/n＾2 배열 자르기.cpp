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

vector<int> solution( int n, long long left, long long right )
{
    vector<int> ans;

    for( long long i = left; i <= right; ++i )
    {
        ans.push_back( max( i / n, i % n ) + 1 );
    }
    return ans;
}