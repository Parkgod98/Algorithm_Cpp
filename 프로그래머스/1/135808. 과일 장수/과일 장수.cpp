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
using namespace std;

int solution( int k, int m, vector<int> score )
{
    int answer = 0;
    sort( score.begin(), score.end(), greater<int>() );
    for( int i = 0; i < score.size(); i+=m )
    {
        if( i + m <= score.size() )
        {
            answer += score[i+m-1]*m;
        }
    }
    return answer;
}