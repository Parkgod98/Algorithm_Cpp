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

int solution( int cacheSize, vector<string> cities )
{
    list<string> dq;
    unordered_map<string, list<string>::iterator> mp;

    int time = 0;
    for( int i = 0; i < cities.size(); ++i )
    {
        string s = cities[i];
        transform( s.begin(), s.end(), s.begin(), ::tolower );

        if( mp.find( s ) == mp.end() ) // 캐시에 없다면
            time += 5;
        else                            // 캐시에 있다면.
            time += 1;

        /* 캐시에 삽입 할 과정 */
        if( dq.size() < cacheSize ) // 캐시가 아직 꽉 차지 않았을떄.
        {
            if( mp.find( s ) == mp.end() ) // 이 값이 아직 캐시에 없다면
            {
                dq.push_front( s );         // dq에 값 넣어주고
                mp[s] = dq.begin();         // 캐시에 값 있다고 표시.
            }
            else                        // 값이 이미 캐시에 있다면
            {
                dq.erase( mp[s]);      // 값을 지워주고
                dq.push_front( s );   // 앞에 새로 삽입. 맵을 건드릴 필요는 없음.
                mp[s] = dq.begin();
            }
        }
        else // 캐시가 꽉 찼다면.
        {
            if( cacheSize != 0 )
            {
                if( mp.find( s ) == mp.end() ) // 캐시 안에 이 값이 없다면
                {
                    dq.push_front( s );           // dq에 새 값 넣어주고
                    mp[s] = dq.begin();         // 캐시에 이거 들어있다고 표시하고.
                    string tmp = dq.back();     // dq마지막 값이 뭔지 확인하고
                    mp.erase( tmp );            // 이제 캐시 없다고 말해주고
                    dq.pop_back();              // 뒤에서도 제거.
                }
                else
                {                           // 캐시 안에 이미 값이 있다면
                    dq.erase( mp[s] );          // 지우고
                    dq.push_front( s );         // 앞에 넣어서 최신화 해주기.
                    mp[s] = dq.begin();
                }
            }
        }
    }
    return time;
}
