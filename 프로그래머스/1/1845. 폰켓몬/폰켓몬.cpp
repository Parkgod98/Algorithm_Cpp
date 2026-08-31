#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    set<int> s;
    for (int &n : nums)
        s.insert(n);
    
    int sz = nums.size()/2;
    
    return min(sz,(int)s.size());
}