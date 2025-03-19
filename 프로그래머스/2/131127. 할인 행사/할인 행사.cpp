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
using namespace std;
// 2, 1, 1, 2, 3, 1, 2, 3, 1

//1 ≤ want의 길이 = number의 길이 ≤ 10
//1 ≤ number의 원소 ≤ 10
//number[i]는 want[i]의 수량을 의미하며, number의 원소의 합은 10입니다.
//10 ≤ discount의 길이 ≤ 100, 000
//want와 discount의 원소들은 알파벳 소문자로 이루어진 문자열입니다.
//1 ≤ want의 원소의 길이, discount의 원소의 길이 ≤ 12
int solution( vector<string> want, vector<int> number, vector<string> discount )
{
    map<string, int> mp;
    for( int i = 0; i < number.size(); ++i )
        mp[want[i]] = number[i];

    int cnt = 0;
    for( int i = 0; i < discount.size(); ++i )
    {
        map<string, int> tmp;
        for( int j = i; j < discount.size() && j < i + 10; ++j )
        {
            if( tmp[discount[j]] )
                tmp[discount[j]]++;
            else
                tmp[discount[j]] = 1;
        }
        bool flag = true;
        for( int i = 0; i < mp.size(); ++i )
        {
            if( tmp.find(want[i]) != tmp.end() )
            {
                if( mp[want[i]] > tmp[want[i]] )
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                flag = false;
                break;
            }
        }
        if( flag )
            ++cnt;
    }
    return cnt;;
}