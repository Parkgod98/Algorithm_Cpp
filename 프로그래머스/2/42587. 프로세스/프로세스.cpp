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


int solution( vector<int> priorities, int location )
{
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    for( int i = 0; i < priorities.size(); ++i )
    {
        pq.push( priorities[i] );
        q.push( { i,priorities[i] } );
    }

    int cnt = 0;
    while( !q.empty() )
    {
        pair<int, int> p = q.front();
        q.pop();
        if( p.second < pq.top() )
        {
            q.push( p );
        }
        else
        {
            pq.pop();
            ++cnt;
            if( p.first == location )
                return cnt;
        }
    }

}