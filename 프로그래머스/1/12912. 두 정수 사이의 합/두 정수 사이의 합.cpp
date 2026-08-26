#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b) {
    if(a > b)
        swap(a,b);
    return (long long)(a+b)*(b-a+1)/2;
}