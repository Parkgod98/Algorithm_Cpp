#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cctype>
#include <queue>
#include <bitset>
using namespace std;


vector<string> solution( int n, vector<int> arr1, vector<int> arr2 ) {
    vector<string> answer;
    for( int i = 0; i < n; ++i ){
        int k = arr1[i] | arr2[i];
        string s = "";
        for( int j = 0; j < n; ++j ){
            if( ( k & 1 ) == 1 )
                s += "#";
            else
                s += " ";
            k = k >> 1;
        }
        answer.push_back( string( s.rbegin(), s.rend() ) );
    }
    return answer;
}