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

int cnt = 0;

void DFS( int sum, int &target, int depth, vector<int>& numbers )
{
    if( depth == numbers.size())
    {
        if( target == sum )
            ++cnt;
        return;

    }
    DFS( sum + numbers[depth], target, depth + 1, numbers );
    DFS( sum - numbers[depth], target, depth + 1, numbers );
}

int solution( vector<int> numbers, int target )
{
    DFS( 0, target, 0, numbers );
    return cnt;
}