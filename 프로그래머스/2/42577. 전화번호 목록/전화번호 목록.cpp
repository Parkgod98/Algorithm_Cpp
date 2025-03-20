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


bool solution( vector<string> phone_book )
{
    sort( phone_book.begin(), phone_book.end() );

    for( int i = 0; i < phone_book.size() - 1; ++i )
    {
        if( phone_book[i + 1].find( phone_book[i] ) == 0 )
            return false;
    }
    return true;
}
