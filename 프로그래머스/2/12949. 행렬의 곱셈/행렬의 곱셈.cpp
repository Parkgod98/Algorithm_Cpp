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

vector<vector<int>> solution( vector<vector<int>> arr1, vector<vector<int>> arr2 )
{
    vector<vector<int>> v(arr1.size(), vector<int>(arr2[0].size(), 0));

    for( int i = 0; i < arr1.size(); ++i )
    {
        for( int j = 0; j < arr2[0].size(); ++j )
        {
            for( int k = 0; k < arr1[0].size(); ++k )
                v[i][j] += arr1[i][k] * arr2[k][j];
        }
    }
    return v;
}