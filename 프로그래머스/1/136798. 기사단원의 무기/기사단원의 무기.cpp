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

int CountDivisor( int n ){
    int sum = 0;
    for( int i = 1; i <= sqrt( n ); ++i ){
        if( n % i == 0 ){
            if( i * i != n )
                sum += 2;
            else
                sum += 1;
        }
    }
    return sum;
}


int solution( int number, int limit, int power ) {
    int answer = 0;

    for( int i = 1; i <= number; ++i ){
        int attack = CountDivisor( i );
        if( attack > limit )
            answer += power;
        else
            answer += attack;
    }

    return answer;
}