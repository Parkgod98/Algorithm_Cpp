#include <vector>
#include <set>
using namespace std;

int solution( vector<int> nums )
{
    int limit = nums.size() / 2;
    set<int> s( nums.begin(), nums.end() );

    if( s.size() >= limit )
        return limit;
    else
        return s.size();
}