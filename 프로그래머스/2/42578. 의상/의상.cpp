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

int solution( vector<vector<string>> clothes )
{
    map<string, int> mp;
    for( auto& p : clothes )
    {
        mp[p[1]]++;
    }
    int ans = 1;
    for( auto& a : mp )
        ans = ans*(a.second+1 );

    return ans-1;
}