#include <string>
#include <vector>

using namespace std;

int solution( int n, int m, vector<int> section )
{
    int answer = 1;
    int start = section[0] + m - 1;
    for( int i = 1; i < section.size(); ++i )
    {
        if( section[i] > start )
        {
            start = section[i] + m - 1;
            answer++;
        }
        
    }
    return answer;
}