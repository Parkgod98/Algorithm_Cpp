#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long r = sqrt(n);
    
    return sqrt(n) == (long long)sqrt(n) ? (r+1) * (r+1) : -1;
}