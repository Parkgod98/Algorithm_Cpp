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

int arr[11][11];
set<pair<pair<int, int>, pair<int, int>>> visited_path;

map<char, int> mat = { {'U',0},{'R',1},{'D',2},{'L',3} };

int solution( string dirs )
{
    for( int i = 0; i < 11; ++i )
    {
        fill( arr[i], arr[i] + 11, 0 );
    }

    int sy, sx;
    sy = sx = 5;
    int cnt = 0;

    for( int i = 0; i < dirs.size(); ++i )
    {
        int ny = sy + dy[mat[dirs[i]]];
        int nx = sx + dx[mat[dirs[i]]];
        if( ny < 0 || nx < 0 || ny >= 11 || nx >= 11 )
            continue;
        pair<int, int> from = { sy,sx };
        pair<int, int> to = { ny,nx };
        if( from > to )
            swap( from, to );
        if( visited_path.find( { from, to } ) == visited_path.end() )
            ++cnt;
        visited_path.insert( { from,to } );
        sy = ny;
        sx = nx;
    }
    return cnt;
}