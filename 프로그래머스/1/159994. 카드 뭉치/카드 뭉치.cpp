#include <string>
#include <vector>

using namespace std;

string solution( vector<string> cards1, vector<string> cards2, vector<string> goal ) {
    int p1, p2;
    p1 = p2 = 0;
    for( int i = 0; i < goal.size(); ++i ){
        if( p1 < cards1.size() && cards1[p1] == goal[i] ){
            p1++;
        }
        else if( p2 < cards2.size() && cards2[p2] == goal[i] )
            p2++;
        else
            return "No";
    }
    return "Yes";
}